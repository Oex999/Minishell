/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:53:48 by oexall            #+#    #+#             */
/*   Updated: 2016/07/08 14:39:58 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**ft_splitcommands(char *str)
{
	char	**cmds;

	cmds = ft_strsplit(str, ';');
	return (cmds);
}

void	ft_loop(t_env *env)
{
	char	*line;
	char	**cmds;
	char	**args;
	int		status;

	status = 1;
	ft_getenv("USER", &env->username, &env);
	ft_printf("\033c");
	while (status)
	{
		ft_printf("[%s]$>", env->username);
		get_next_line(0, &line);
		cmds = ft_splitcommands(line);
		while (*cmds)
		{
			args = ft_split(*cmds);
			status = ft_execute(args, &env);
			if (status == 0)
				break ;
			cmds++;
		}
	}
	free(env->username);
}
