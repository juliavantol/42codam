/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 22:54:38 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/24 13:49:59 by juvan-to      ########   odam.nl         */
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
}	t_cmd;

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_exe
{
	struct s_cmd	**commands;
	int				command_count;
	int				status;
	int				exit_code;
	int				index;
	int				old_fds[2];
	int				fds[2];
	char			*current_directory;
	char			*input;
	char			**paths;
	t_envp			*envp_list;
}	t_exe;

void	empty_executor(t_exe *executor);
void	start_executor(t_exe *executor, int i);
void	temp_parser(t_exe *executor, char *input);
void	init_executor(t_exe *executor, char **envp);
void	redirect_output(t_cmd *command);
void	redirect_input(t_cmd *command);
void	empty_array(char **arr);
void	error_exit(char *msg);
void	cmd_error(char *cmd);
bool	check_builtin(t_exe *executor, t_cmd *command);
char	**convert_envp(t_exe *executor);

char	*get_cmd_path(t_exe *executor, char *cmd, char **envp, int i);
char	**ft_split_paths(char *whole_str);
char	**get_paths(char **envp);
char	**ft_split_args(char *s);
char	**manual_envp(void);
char	*get_next_line(int fd);

int		open_file(char *filename, int mode);
int		search_newline(char *s);

bool	ft_strcmp(char *s1, char *s2);
void	add_node(t_filenames **filenames, char *name, int mode);
void	free_cmds(t_exe *executor);
void	exit_shell(t_exe *executor, int code);
void	free_command(t_cmd	*command);
char	*get_pwd(void);

void	print_env(t_exe *executor);

#endif