/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:25:26 by oexall            #+#    #+#             */
/*   Updated: 2016/07/08 06:51:04 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_improper(char *cmd, char *arg, int err)
{
	if (err == 1)
		ft_printf(E_NONEXISTANT, cmd, arg);
	else if (err == 2)
		ft_printf(E_INVALIDARGS, cmd, arg);
	else if (err == 3)
		ft_printf(E_DENIEDACCESS, cmd, arg);
	else if (err == 4)
		ft_printf(E_NOTDIR, cmd, arg);
	return (1);
}

int		ft_count(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int		ft_cd(char **args, t_env **env)
{
	char	*path;

	if (ft_count(args) > 2)
		return (ft_improper(args[0], args[1], 2));
	if (args[1] != NULL)
		path = args[1];
	if (args[1] == NULL || args[1][0] == '~')
		if (ft_getenv("HOME", &path, env) == -1)
			return (ft_printf("cd: Failed to get Home Dir\n"));
	if (args[1] != NULL && args[1][0] == '~' && args[1][1] != '\0')
		path = ft_strjoin(path, ft_strchr(args[1], '/'));
	if (access(path, F_OK) != 0)
		return (ft_improper(args[0], path, 1));
	if (access(path, R_OK) != 0)
		return (ft_improper(args[0], path, 3));
	if (chdir(path) != 0)
		return (ft_improper(args[0], path, 4));
	(*env)->old_pwd = (*env)->pwd;
	ft_update_env("OLDPWD", (*env)->old_pwd, env);
	ft_strdel(&(*env)->pwd);
	(*env)->pwd = getcwd(NULL, 0);
	ft_update_env("PWD", (*env)->pwd, env);
	return (1);
}
