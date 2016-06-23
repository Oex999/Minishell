/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:08:55 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 16:30:01 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_path(char *prog)
{
	char	*path;
	
	path = ft_strjoin("/bin/", prog);
	return (path);
}

int		ft_execute(char **args, t_env **env)
{
	if (args[0] == NULL)
		return (1);	
	if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	if (ft_strcmp(args[0], "clear") == 0)
		return (ft_printf("\033c"));
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args, env));
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_putenv(env));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_printf("%s\n", (*env)->pwd));
	if (ft_strcmp(args[0], "setenv") == 0)
		return (ft_setenv(args, env));
	if (ft_strcmp(args[0], "unsetenv") == 0)
		return (ft_unsetenv(args[1], env));
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
			ft_printf("%s: Command not found.\n", args[0]);
	}
	return (1);
}
