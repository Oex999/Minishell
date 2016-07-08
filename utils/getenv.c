/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 07:31:52 by oexall            #+#    #+#             */
/*   Updated: 2016/07/07 06:41:10 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenvstr(char *search, t_env *envi)
{
	int		i;

	i = 0;
	while (envi->env[i])
	{
		if (ft_strncmp(envi->env[i], search, ft_strlen(search)) == 0)
			return (ft_strchr(envi->env[i], '='));
		i++;
	}
	return (NULL);
}

int		ft_getenv(char *search, char **value, t_env **environ)
{
	t_env	*env;
	int		index;

	env = *environ;
	index = 0;
	while (env->env[index])
	{
		if (ft_strncmp(env->env[index], search, ft_strlen(search)) == 0)
		{
			if (value != NULL)
				*value = ft_strsplit(env->env[index], '=')[1];
			return (index);
		}
		index++;
	}
	return (-1);
}
