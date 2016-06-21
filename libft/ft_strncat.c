/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:02:22 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/14 12:46:26 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*s1_t;
	const char	*s2_t;

	if (n != 0)
	{
		i = 0;
		s1_t = s1;
		s2_t = s2;
		while (*s1_t != '\0')
			s1_t++;
		while (i < n)
		{
			*s1_t = *s2_t;
			s1_t++;
			s2_t++;
			i++;
		}
		*s1_t = '\0';
	}
	return (s1);
}
