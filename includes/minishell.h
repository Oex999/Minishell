/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 08:32:16 by oexall            #+#    #+#             */
/*   Updated: 2016/07/04 07:43:44 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include "errors.h"
# include "../libft/libft.h"

typedef struct	s_env
{
	char		*username;
	char		**env;
	char		*pwd;
	char		*old_pwd;
}				t_env;

int				ft_puterror(char *arg, char *error);
int				ft_count(char **args);
char			*ft_pathto(char *path1, char *path2, char sep);

void			ft_loop(t_env *env);
int				ft_execute(char **args, t_env **env);
int				ft_launch(char **args, t_env **env);
char			**ft_split(char *str);

int				ft_cd(char **args, t_env **env);
int				ft_echo(char **args);
int				ft_setenv(char **args, t_env **env);
int				ft_unsetenv(char *name, t_env **env);

char			**ft_duptab(char **env, int len);
void			ft_deltab(char **env);

int				ft_getenv(char *search, char **value, t_env **environ);
char			*ft_getenvstr(char *search, t_env *environ);
int				ft_putenv(t_env **env);
int				ft_update_env(char *var, char *value, t_env **env);

#endif
