/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 23:08:03 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/07 15:52:29 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_output(void)
{
	int		fds[2];
	char	*buffer;
	pid_t	pid;

	buffer = NULL;
	if (pipe(fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		buffer = here_doc("test", NULL);
		exit(0);
	}
	else
	{
		close(fds[0]);
		wait(NULL);
		printf("%s\n", buffer);
		close(fds[1]);
	}
}

char	*here_doc2(char *delimiter, char *input)
{
	char	*temp;
	char	*buffer;
	size_t	len;

	len = ft_strlen(delimiter);
	buffer = ft_strdup("");
	while (1)
	{
		input = get_next_line(0);
		if (ft_strnstr(input, delimiter, len)
			&& ft_strlen(input) <= len + 1 && input[len] == '\n')
			break ;
		if (buffer)
		{
			temp = join_str(buffer, input);
			free(buffer);
			buffer = temp;
		}
		else
			buffer = ft_strdup(input);
		free(input);
	}
	free(input);
	return (buffer);
}

char	*here_doc(char *delimiter, char *input)
{
	int		heredoc_file;
	char	*buffer;

	heredoc_file = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	buffer = here_doc2(delimiter, input);
	write(heredoc_file, buffer, ft_strlen(buffer));
	//unlink(".here_doc");
	return (input);
}
