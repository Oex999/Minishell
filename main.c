/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 08:32:05 by oexall            #+#    #+#             */
/*   Updated: 2016/06/21 08:41:27 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf("$>");
		get_next_line(0, &line);
		args = ft_strsplit(line, ' ');
		status = ft_execute(args);
		free(line);
		free(args);
	}
}

int		main(int argc, char **argv)
{
	ft_loop();
	return (0);
}
