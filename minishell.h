/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 08:32:16 by oexall            #+#    #+#             */
/*   Updated: 2016/06/20 16:41:31 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

void	ft_puterror(char *str);

void	ft_loop(void);
int		ft_execute(char **args);
int		ft_launch(char **args);

int		ft_pwd(void);
int		ft_cd(char **args);
int		ft_echo(char **args);

#endif
