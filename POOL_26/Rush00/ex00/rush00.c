/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 23:14:55 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/19 11:41:28 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0)
		return ;
	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			if ((row == 1 || row == y) && (col == 1 || col == x))
				ft_putchar('o');
			else if ((row == 1 || row == y) && (col > 1 && col < x))
				ft_putchar('-');
			else if ((row > 1 && row < y) && (col == 1 || col == x))
				ft_putchar('|');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
