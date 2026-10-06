/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:04:57 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/16 21:54:57 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	start;
	char	end;

	start = 'z';
	end = 'a';
	while (start >= end)
	{
		ft_putchar(start);
		start--;
	}
}
/*
int main()
{
	ft_print_reverse_alphabet();
}
*/
