/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:53:48 by oexall            #+#    #+#             */
/*   Updated: 2016/07/08 10:19:09 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_loop(t_env *env)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	ft_getenv("USER", &env->username, &env);
	ft_printf("\033c");
	while (status)
	{
		line = NULL;
		args = NULL;
		ft_printf("[%s]$>", env->username);
		get_next_line(0, &line);
		args = ft_split(line);
		status = ft_execute(args, &env);
		free(line);
		ft_deltab(args);
	}
	free(env->username);
}
