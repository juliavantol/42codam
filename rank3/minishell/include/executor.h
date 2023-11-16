/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 22:54:38 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/16 15:13:43 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/types.h>
# include <sys/wait.h>
# include "minishell.h"
# include "libft.h"

# define READ 0
# define WRITE 1
# define INPUT 0
# define OUTPUT 1
# define APPEND 1
# define TRUNCATE 2
# define HEREDOC 3
# define QUIT 1

typedef struct s_builtins	t_builtins;

typedef struct s_filenames
{
	char				*filename;
	int					mode;
	char				*delimiter;
	struct s_filenames	*next;
}	t_filenames;

typedef struct s_cmd
{
	char			*command_name;
	char			**split;
	bool			output_redirection;
	bool			input_redirection;
	t_filenames		*outputs;
	t_filenames		*inputs;
	int				index;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_exe
{
	int				command_count;
	int				exit_code;
	int				fds[2];
	int				input_fd;
	int				index;
	int				status;
	char			*current_directory;
	char			*input;
	char			**paths;
	t_builtins		*builtins;
	pid_t			*pids;
	t_cmd			*commands_list;
	t_envp			*envp_list;
}	t_exe;

typedef struct s_builtins
{
	char	*command;
	void	(*function)(t_exe *, t_cmd *);
}	t_builtins;

void	add_command_node(t_cmd **commands, char *command_line_split, int index);
void	divide_command_in_redirections(t_cmd *node, char *command, int i);
void	wait_for_all_child_processes(t_exe *executor);
void	here_doc(t_filenames *head, char *delimiter);
void	add_redirection(t_filenames **filenames, char *name, int mode);
void	exit_shell(t_exe *executor, int code, t_cmd *command);
void	init_executor(t_exe *executor, char **envp);
void	temp_parser(t_exe *executor, char *input);
void	free_redirection(t_filenames *node);
void	free_command_list(t_exe *executor);
void	ft_error(char *msg, int err_code);
void	handle_heredocs(t_exe *executor);
void	redirect_output(t_cmd *command);
void	reset_executor(t_exe *executor);
void	empty_executor(t_exe *executor);
void	start_executor(t_exe *executor);
void	redirect_input(t_cmd *command);
void	empty_array(char **arr);
void	error_exit(char *msg);
void	cmd_error(char *cmd);

char	*get_cmd_path(t_exe *executor, char *cmd, char **envp, int i);
char	**ft_split_paths(char *whole_str);
char	**convert_envp_to_char(t_exe *executor);
char	*get_current_directory(void);
char	**get_paths(char **envp);
char	**ft_split_args(char *s);
char	*get_next_line(int fd);
char	**manual_envp(void);

int		open_file(char *filename, int mode);
int		search_newline(char *s);
int		ctrl_d(t_exe *executor);

bool	check_builtin(t_exe *executor, t_cmd *command);
bool	ft_strcmp(char *s1, char *s2);

#endif
