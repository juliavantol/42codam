/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 22:54:38 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/17 13:23:46 by juvan-to      ########   odam.nl         */
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
# define APPEND 0
# define TRUNCATE 1
# define HEREDOC 2

typedef struct s_filenames
{
	char				*filename;
	int					index;
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

typedef struct s_exe
{
	char			**commands;
	struct s_cmd	**all_commands;
	int				command_count;
	int				exit_status;
	int				*pids;
	int				index;
	int				old_fds[2];
	int				fds[2];
	char			**envp;
	char			**paths;
	char			**minishell_envp;
}	t_exe;

void	empty_executor(t_exe *executor);
void	start_executor(t_exe *executor);
void	temp_parser(t_exe *executor, char *input);
void	check_command(t_exe *executor, char *input);
void	init_executor(t_exe *executor, char **envp);
void	redirect_output(t_cmd *command);
void	redirect_input(t_cmd *command);
void	empty_int_array(int *arr);
void	empty_array(char **arr);
void	error_exit(char *msg);
void	cmd_error(char *cmd);

char	*get_cmd_path(char **paths, char	*cmd);
char	**ft_split_paths(char *whole_str);
char	**get_paths(char **envp);
char	**ft_split_args(char *s);
char	**manual_envp(void);
char	*get_next_line(int fd);

int		search_newline(char *s);

bool	ft_strcmp(char *s1, char *s2);
void	add_node(t_filenames **filenames, char *name, int mode, int index);

#endif