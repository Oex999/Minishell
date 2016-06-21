/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:08:55 by oexall            #+#    #+#             */
/*   Updated: 2016/06/21 07:38:56 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path(char *prog)
{
	char	*path;
	//ADD PATH
	
	path = ft_strjoin("/bin/", prog);
	return (path);
}

int		ft_execute(char **args)
{
	if (args[0] == NULL)
		return (1);	
	if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args));
	if (ft_strcmp(args[0], "clear") == 0)
		ft_printf("\033c");
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	return (ft_launch(args));
}

int		ft_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/", args, NULL) == -1)
			ft_printf("msh: Error starting process\n");
	}
	else if (pid < 0)
		ft_printf("msh: Error forking process\n");
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
	}
	return (1);
}
