/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 00:15:10 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/05 00:15:13 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

# define ERROR_DEV "Stop : division by zero\n"
# define ERROR_MOD "Stop : modulo by zero\n"
# define OPERATORS "+-*/%"
# define ZERO "0\n"

int		ft_atoi(char *str);
int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mult(int a, int b);
int		ft_mod(int a, int b);
int		ft_div(int a, int b);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	init_fts(int (*ptr_fts[])(int, int));

#endif
