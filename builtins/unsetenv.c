/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:22:55 by oexall            #+#    #+#             */
/*   Updated: 2016/07/08 12:51:18 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_unsetenv(char **args, t_env **env)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	if (args[0] && !(args[1]))
		return (ft_puterror("unsetenv", "Argument Needed"));
	while (args[0] && (*env)->env[i])
	{
		if (ft_strncmp((*env)->env[i], args[1], ft_strlen(args[0])) == 0)
		{
			ft_strdel(&(*env)->env[i]);
			res = 1;
			while ((*env)->env[i + 1])
			{
				(*env)->env[i] = (*env)->env[i + 1];
				(*env)->env[i + 1] = NULL;
				++i;
			}
		}
		++i;
	}
	return (res);
}
