/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 10:33:05 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 13:14:28 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_setenv(char **args, t_env **env)
{
	char	**split;

	if (args[1] == NULL)
		return (ft_puterror("setenv", "No arguments provided"));
	return (1);
}
