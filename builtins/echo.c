/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 14:46:20 by oexall            #+#    #+#             */
/*   Updated: 2016/07/08 12:09:06 by oexall           ###   ########.fr       */
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
	else if (hc == '\"')
		ft_printf("\"");
}

int		ft_printenv(char *var, t_env **env)
{
	char	*search;
	char	*value;
	int		len;

	value = NULL;
	len = 0;
	while (var[len] != ' ' && var[len] && var[len] != '\"')
		len++;
	search = ft_strsub(var, 0, len);
	if (ft_getenv(search, &value, env) != -1)
		ft_printf("%s", value);
	free(search);
	if (value != NULL)
		free(value);
	return (len + 1);
}

void	print_echo(char *str, t_env **env)
{
	int	i;
	int	in_q;

	i = 0;
	in_q = (str[i] == '\"') ? 1 : 0;
	i += (str[i] == '\"');
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			i += ft_printenv(&str[i + 1], env);
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

int		ft_echo(char **args, t_env **env)
{
	int	i;
	int	is_n;

	i = 0;
	is_n = 0;
	if (ft_strcmp(args[i], "echo") == 0)
		i++;
	if (args[i] && ft_strcmp(args[i], "-n") == 0)
		is_n = i++;
	while (args[i] && args[i] != NULL)
	{
		print_echo(args[i], env);
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
