/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:22:55 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 16:27:59 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_unsetenv(char *name, t_env **env)
{
	int		res;
	int		i;
	char	**env_ptr;

	res = 0;
	i = 0;
	env_ptr = (*env)->env;
	while (*name && env_ptr[i])
	{
		if (ft_strncmp(env_ptr[i], name, ft_strlen(name)) == 0)
		{
			ft_strdel(&env_ptr[i]);
			res = 1;
			while (env_ptr[i + 1])
			{
				env_ptr[i] = env_ptr[i + 1];
				env_ptr[i + 1] = NULL;
				++i;
			}
		}
		++i;
	}
	return (res);
}
