#include <unistd.h>
#include <stdlib.h>

// Graph node structure
typedef struct s_node {
    int id;
    int *neighbors;
    int neighbor_count;
} t_node;

// Helper function prototypes
t_node *parse_input(char *input, int *node_count);
void add_edge(t_node *graph, int u, int v);
int dfs(t_node *graph, int node_id, int *visited, int node_count, int depth);
void graph_free(t_node *graph, int node_count);
int get_or_create_node(t_node *graph, int *node_count, int id);

// Utility to convert an integer to a string and write it
void write_number(int n) {
    char buffer[12];
    int i = 0;

    if (n == 0) {
        write(1, "0\n", 2);
        return;
    }

    while (n > 0) {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    for (int j = i - 1; j >= 0; j--) {
        write(1, &buffer[j], 1);
    }
    write(1, "\n", 1);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }
    
    int node_count = 0;
    t_node *graph = parse_input(argv[1], &node_count);

    if (!graph) {
        write(1, "\n", 1);
        return 0;
    }

    // Perform DFS on all nodes to find the longest path
    int max_chain = 0;
    for (int i = 0; i < node_count; i++) {
        int *visited = (int *)malloc(sizeof(int) * node_count);
        for (int j = 0; j < node_count; j++)
            visited[j] = 0;
        
        int chain_length = dfs(graph, i, visited, node_count, 1);
        if (chain_length > max_chain)
            max_chain = chain_length;
        
        free(visited);
    }

    // Output the longest chain length
    write_number(max_chain);

    // Free the graph
    graph_free(graph, node_count);

    return 0;
}

// Helper function to parse input and build the graph
t_node *parse_input(char *input, int *node_count) {
    t_node *graph = (t_node *)malloc(sizeof(t_node) * 100);  // Assuming at most 100 unique nodes
    if (!graph)
        return NULL;

    for (int i = 0; i < 100; i++) {
        graph[i].id = -1;
        graph[i].neighbors = NULL;
        graph[i].neighbor_count = 0;
    }

    int i = 0;
    while (input[i]) {
        // Parse one link
        int u = 0, v = 0;
        while (input[i] && input[i] != '-') {
            u = u * 10 + (input[i] - '0');
            i++;
        }
        i++;  // Skip '-'
        while (input[i] && input[i] != ' ') {
            v = v * 10 + (input[i] - '0');
            i++;
        }
        if (input[i] == ' ') i++;  // Skip space

        // Add the edge to the graph
        int u_index = get_or_create_node(graph, node_count, u);
        int v_index = get_or_create_node(graph, node_count, v);
        add_edge(graph, u_index, v_index);
    }

    return graph;
}

// Adds an edge between two nodes u and v
void add_edge(t_node *graph, int u, int v) {
    // Add v to u's neighbor list
    graph[u].neighbors = (int *)realloc(graph[u].neighbors, sizeof(int) * (graph[u].neighbor_count + 1));
    graph[u].neighbors[graph[u].neighbor_count] = v;
    graph[u].neighbor_count++;

    // Add u to v's neighbor list
    graph[v].neighbors = (int *)realloc(graph[v].neighbors, sizeof(int) * (graph[v].neighbor_count + 1));
    graph[v].neighbors[graph[v].neighbor_count] = u;
    graph[v].neighbor_count++;
}

// DFS function to find the longest path starting from node_id
int dfs(t_node *graph, int node_id, int *visited, int node_count, int depth) {
    visited[node_id] = 1;
    int max_depth = depth;

    for (int i = 0; i < graph[node_id].neighbor_count; i++) {
        int neighbor_id = graph[node_id].neighbors[i];
        if (!visited[neighbor_id]) {
            int new_depth = dfs(graph, neighbor_id, visited, node_count, depth + 1);
            if (new_depth > max_depth)
                max_depth = new_depth;
        }
    }

    visited[node_id] = 0;  // Unmark the node for further exploration
    return max_depth;
}

// Function to get or create a node in the graph
int get_or_create_node(t_node *graph, int *node_count, int id) {
    for (int i = 0; i < *node_count; i++) {
        if (graph[i].id == id)
            return i;
    }
    graph[*node_count].id = id;
    return (*node_count)++;
}

// Function to free the graph memory
void graph_free(t_node *graph, int node_count) {
    for (int i = 0; i < node_count; i++) {
        if (graph[i].neighbors)
            free(graph[i].neighbors);
    }
    free(graph);
}
