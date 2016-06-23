/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:16:11 by oexall            #+#    #+#             */
/*   Updated: 2016/06/21 10:54:59 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_pwd(void)
{
	char	*w_dir;

	w_dir = getcwd(NULL, 0);
	ft_printf("%s\n", w_dir);
	free(w_dir);
	return (1);
}

int		ft_echo(char **args)
{
	int	i;

	i = 1;
	while (args[i] != '\0' && args[i] && args[i] != NULL)
	{
		ft_printf("%s ", args[i]);
		i++;
	}
	ft_printf("\n");
	return (1);
}
