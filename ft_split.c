/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 09:53:46 by oexall            #+#    #+#             */
/*   Updated: 2016/06/24 13:21:12 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_skipqoutes(char **line)
{
	if (**line == '\"')
		(*line)++;
	while (**line != '\"' && **line != '\0')
		(*line)++;
	if (**line == '\"' && **line != '\0')
		(*line)++;
	return (1);
}

int		ft_count_args(char *line)
{
	int	c;
	int	in_w;

	in_w = 0;
	c = 0;
	while (*line)
	{
		if (*line == '\"')
			c += ft_skipqoutes(&line);
		if (in_w == 0 && *line != ' ' && *line != '\t')
			in_w = 1;
		if (in_w == 1 && (*line == ' ' || *line == '\t' || line[1] == '\0'))
		{
			in_w = 0;
			if (*line != '\0')
				c++;
		}
		line++;
	}
	return (c);
}

char	**ft_split(char *str)
{
	char	*start;
	char	**res;
	int		n_args;
	int		i;

	n_args = ft_count_args(str);
	res = (char **)malloc(sizeof(char *) * (n_args + 1));
	start = str;
	i = 0;
	while (*str)
	{
		if (*str == '\"')
			ft_skipqoutes(&str);
		if (*str == ' ' || *str == '\t' || str[1] == '\0')
		{
			res[i] = ft_strsub(start, 0, str - start + (i + 1 == n_args));
			start = str + 1;
			i++;
		}
		str++;
	}
	res[i] = NULL;
	return (res);
}
