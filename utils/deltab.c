/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deltab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:48:02 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 15:49:43 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_deltab(char **env)
{
	int	i;

	if (env)
	{
		i = 0;
		while (env[i])
		{
			free(env[i]);
			env[i] = NULL;
			i++;
		}
		free(env);
	}
}
