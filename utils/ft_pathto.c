/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:19:29 by oexall            #+#    #+#             */
/*   Updated: 2016/06/24 09:35:25 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_pathto(char *path1, char *path2, char sep)
{
	char	*n_path;
	int		len;
	int		i;

	len = ft_strlen(path1) + ft_strlen(path2) + 2;
	if (!(n_path = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (*path1)
	{
		n_path[i++] = *path1;
		path1++;
	}
	n_path[i++] = sep;
	while (*path2)
	{
		n_path[i++] = *path2;
		path2++;
	}
	n_path[len] = '\0';
	return (n_path);
}
