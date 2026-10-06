/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:38:19 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/21 22:17:36 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

void	ft_putstr_non_printable(char *str)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	while (*str)
	{
		if (ft_is_printable(*str))
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_putchar(hexa[(unsigned char)*str / 16]);
			ft_putchar(hexa[(unsigned char)*str % 16]);
		}
		str++;
	}
}
/*
int	main()
{
	char str[] = "H\ne\rllo\nHow are you?\t";

	ft_putstr_non_printable(str);
}
*/
