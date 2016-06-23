/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 07:31:52 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 07:50:41 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_getenv(char *search, char **value, t_env **environ)
{
	t_env	*env;
	int		index;
	char	*val;

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
