/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 14:46:20 by oexall            #+#    #+#             */
/*   Updated: 2016/06/24 15:40:47 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_hidden(char hc)
{
	if (hc == 'n')
		ft_printf("\n");
	else if (hc == 't')
		ft_printf("\t");
	else if (hc == 'v')
		ft_printf("\v");
	else if (hc == 'r')
		ft_printf("\r");
	else if (hc == 'f')
		ft_printf("\f");
	else if (hc == 'a')
		ft_printf("\a");
	else if (hc == 'b')
		ft_printf("\b");
}

void	print_echo(char *str)
{
	int	i;
	int	in_q;

	i = 0;
	in_q = (str[i] == '\"') ? 1 : 0;
	i += (str[i] == '\"');
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && str[i + 1] != '\0')
		{
			if (str[i + 1] == '\\')
				i++;
			if (in_q == 1)
				print_hidden(str[i + 1]);
			i += (in_q == 1) ? 2 : 1;
			continue;
		}
		if (str[i] != '\"')
			ft_putchar(str[i]);
		i++;
	}
}

int		ft_echo(char **args)
{
	int	i;

	i = 0;
	if (ft_strcmp(args[i], "echo") == 0)
		i++;
	while (args[i] != NULL)
	{
		print_echo(args[i]);
		if (args[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}
