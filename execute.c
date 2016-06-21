/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:08:55 by oexall            #+#    #+#             */
/*   Updated: 2016/06/21 08:33:32 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path(char *prog)
{
	char	*path;
	
	path = ft_strjoin("/bin/", prog);
	return (path);
}

int		ft_execute(char **args)
{
	if (args[0] == NULL)
		return (1);	
	if (ft_strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args));
	if (ft_strcmp(args[0], "clear") == 0)
		return (ft_printf("\033c"));
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	return (ft_launch(args));
}

int		ft_launch(char **args)
{
	pid_t	pid;
	int		status;

	pid = fork();
	status = 1;
	if (pid > 0)
	{
		wait(&status);
	}
	if (pid == 0 && args[0] != NULL)
	{
		if (execve(ft_path(args[0]), args, NULL) == -1)
			ft_printf("%s: Command not found. (msh)\n", args[0]);
	}
	return (1);
}
