/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updateenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 09:03:28 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 09:58:27 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_update_env(char *var, char *value, t_env **env)
{
	int		index;
	char	*n_val;
	int		i;

	index = ft_getenv(var, NULL, env);
	if (index == -1)
		return (ft_puterror("Update ENV", E_INVALIDVAR));
	n_val = ft_strjoin(var, "=");
	n_val = ft_strjoin(n_val, value);
	if (!((*env)->env[index] = (char *)malloc(sizeof(char) * ft_strlen(n_val))))
		return (ft_puterror("Update ENV", E_MALLOC));
	ft_strclr((*env)->env[index]);
	i = 0;
	while (n_val[i] != '\0')
	{
		(*env)->env[index][i] = n_val[i];
		i++;
	}
	return (1);
}