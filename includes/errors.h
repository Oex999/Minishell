/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 10:57:31 by oexall            #+#    #+#             */
/*   Updated: 2016/06/23 12:36:34 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define E_NONEXISTANT "%s: No such file or directory: %s\n"
# define E_INVALIDARGS "%s: String not in pwd: %s\n"
# define E_DENIEDACCESS "%s: Permission Denied: %s\n"
# define E_NOTDIR "%s: Not a directory: %s\n"

# define E_MALLOC "Failed to malloc"
# define E_INVALIDVAR "No ENV with that name"
# define E_NOARGS "Not enough Arguments"

#endif
