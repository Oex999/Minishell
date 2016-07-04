/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 08:32:05 by oexall            #+#    #+#             */
/*   Updated: 2016/07/04 10:21:36 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**ft_copytab(char **env)
{
	char	**tmp;
	int		i;

	ft_printf("%s\n", env[0]);
	i = 0;
	while (env[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int			main(int argc, char **argv)
{
	extern char		**environ;
	t_env			env;

	env.env = ft_copytab(environ);
	env.pwd = getcwd(NULL, 0);
	env.old_pwd = env.pwd;
	ft_loop(&env);
	free(env.pwd);
	ft_deltab(env.env);
	return (0);
}
