/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 08:32:05 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 13:23:11 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_loop(t_env *env)
{
	char	*line;
	char	**args;
	int		status;

	ft_getenv("LOGNAME", &env->username, &env);
	status = 1;
	while (status)
	{
		ft_printf("[%s]:", env->username);
		get_next_line(0, &line);
		args = ft_strsplit(line, ' ');
		status = ft_execute(args, &env);
		free(line);
		free(args);
	}
}

int		main(int argc, char **argv, char **envi)
{
	t_env			env;

	env.env = envi;
	env.pwd = getcwd(NULL, 0);
	env.old_pwd = env.pwd;
	ft_loop(&env);
	free(env.path);
	return (0);
}
