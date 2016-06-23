/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duptab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:31:55 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 15:44:04 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_duptab(char **env, int len)
{
	char	**tmp;
	int		i;

	if (!(tmp = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (env[++i] && i < len)
		tmp[i] = ft_strdup(env[i]);
	while (++i < len)
		tmp[i][0] = '\0';
	tmp[len] = NULL;
	return (tmp);
}
