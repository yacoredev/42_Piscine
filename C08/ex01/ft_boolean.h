/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:21:07 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/03 00:19:19 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN(nbr) (((nbr) % 2) == 0)
# define TRUE 1
# define FALSE 0
# define SUCCESS 0

typedef int	t_bool;

void		ft_putstr(char *str);
t_bool		ft_is_even(int nbr);

#endif
