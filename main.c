/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 08:32:05 by oexall            #+#    #+#             */
/*   Updated: 2016/06/30 06:43:21 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char	**ft_copytab(char **env)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (env[i])
		i++;
	if (!(tmp = (char **)malloc(sizeof(char *) * (i + 1))))
		ft_puterror("copy_env", "Memory allocation failed.");
	while (env[j])
	{
		tmp[j] = ft_strdup(env[j]);
		j++;
	}
	tmp[j] = NULL;
	return (tmp);
}

int			main(int argc, char **argv, char **environ)
{
	t_env			env;

	env.env = ft_copytab(environ);
	env.pwd = getcwd(NULL, 0);
	env.old_pwd = env.pwd;
	ft_loop(&env);
	free(env.pwd);
	ft_deltab(env.env);
	return (0);
}
