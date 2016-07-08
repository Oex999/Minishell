/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 14:46:20 by oexall            #+#    #+#             */
/*   Updated: 2016/07/07 15:45:08 by oexall           ###   ########.fr       */
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
	int	is_n;

	i = 0;
	is_n = 0;
	if (ft_strcmp(args[i], "echo") == 0)
		i++;
	if (ft_strcmp(args[i], "-n") == 0)
		is_n = i++;
	while (args[i] != NULL)
	{
		print_echo(args[i]);
		if (args[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	if (is_n == 0)
		ft_putchar('\n');
	else
		ft_printf("\e[48;5;254m\e[38;5;0m%%\e[0m\n");
	return (1);
}
