/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 10:33:05 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 16:14:26 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_setenv(char **args, t_env **env)
{
	int		i;
	char	**tmp;
	char	**split;

	if (args[1] == NULL)
		return (ft_puterror("setenv", "No arguments provided"));
	split = ft_strsplit(args[1], '=');
	if (ft_getenv(split[0], NULL, env) != -1)
		return (ft_update_env(split[0], split[1], env));
	i = ft_count((*env)->env);
	tmp = ft_duptab((*env)->env, i + 1);
	tmp[i] = ft_strdup(args[1]);
	ft_deltab((*env)->env);
	(*env)->env = tmp;
	return (1);
}
