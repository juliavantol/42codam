/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 22:54:38 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/27 02:31:59 by Julia         ########   odam.nl         */
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

typedef struct s_filenames
{
	char				*filename;
	int					mode;
	struct s_filenames	*next;
}	t_filenames;

typedef struct s_cmd
{
	char			*command_name;
	bool			output_redirection;
	bool			input_redirection;
	t_filenames		*outputs;
	t_filenames		*inputs;
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
	int				old_fds[2];
	int				fds[2];
	int				status;
	char			*current_directory;
	char			*input;
	char			**paths;
	t_cmd			*commands_list;
	t_envp			*envp_list;
}	t_exe;

void	add_command_node(t_cmd **commands, char *command_line_split);
void	divide_command_in_redirections(t_cmd *node, char *command, int i);
void	add_node(t_filenames **filenames, char *name, int mode);
void	init_executor(t_exe *executor, char **envp);
void	temp_parser(t_exe *executor, char *input);
void	start_executor(t_exe *executor, int i);
void	exit_shell(t_exe *executor, int code);
void	free_command_list(t_exe *executor);
void	ft_error(char *msg, int err_code);
void	redirect_output(t_cmd *command);
void	empty_executor(t_exe *executor);
void	redirect_input(t_cmd *command);
void	print_env(t_exe *executor);
void	empty_array(char **arr);
void	error_exit(char *msg);
void	cmd_error(char *cmd);

char	*get_cmd_path(t_exe *executor, char *cmd, char **envp, int i);
char	**ft_split_paths(char *whole_str);
char	**convert_envp(t_exe *executor);
char	**get_paths(char **envp);
char	**ft_split_args(char *s);
char	*get_next_line(int fd);
char	**manual_envp(void);
char	*get_current_directory(void);

int		open_file(char *filename, int mode);
int		search_newline(char *s);

bool	check_builtin(t_exe *executor, t_cmd *command);
bool	ft_strcmp(char *s1, char *s2);

#endif
