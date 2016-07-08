/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:08:55 by oexall            #+#    #+#             */
/*   Updated: 2016/07/08 10:37:23 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_result(char **args, t_env **env)
{
	char	**all_paths;
	char	*path;
	int		index;
	char	*n_path;

	path = ft_pathto((*env)->pwd, args[0], '/');
	if (execve(path, args, (*env)->env) != -1)
		return (1);
	ft_strdel(&path);
	path = NULL;
	index = 0;
	ft_getenv("PATH", &path, env);
	all_paths = ft_strsplit(path, ':');
	ft_strdel(&path);
	while (all_paths[index] != NULL)
	{
		n_path = ft_pathto(all_paths[index], args[0], '/');
		if (execve(n_path, args, (*env)->env) != -1)
		{
			ft_strdel(&n_path);
			return (1);
		}
		index++;
	}
	return (-1);
}

int		ft_execute(char **args, t_env **env)
{
	if (args[0] == NULL)
		return (1);
	else if (ft_strncmp(args[0], "exit", 4) == 0)
		return (0);
	else if (ft_strncmp(args[0], "clear", 5) == 0)
		return (ft_printf("\033c"));
	else if (ft_strncmp(args[0], "echo", 4) == 0)
		return (ft_echo(args, env));
	else if (ft_strncmp(args[0], "cd", 2) == 0)
		return (ft_cd(args, env));
	else if (ft_strncmp(args[0], "env", 3) == 0)
		return (ft_putenv(env));
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
		return (ft_printf("%s\n", (*env)->pwd));
	else if (ft_strncmp("setenv", args[0], 6) == 0)
		return (ft_setenv(args, env));
	else if (ft_strncmp("unsetenv", args[0], 8) == 0)
		return (ft_unsetenv(args[1], env));
	return (ft_launch(args, env));
}

int		ft_launch(char **args, t_env **env)
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
		if (ft_result(args, env) == -1)
			ft_printf("%s: Command not found.\n", args[0]);
		return (0);
	}
	return (1);
}
