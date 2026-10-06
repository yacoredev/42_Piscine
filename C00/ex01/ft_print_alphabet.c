/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:52:30 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/16 13:06:54 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	start;
	char	end;

	start = 'a';
	end = 'z';
	while (start <= end)
	{
		ft_putchar(start);
		start++;
	}
}

/*
int main()
{
	ft_print_alphabet();
}
*/
