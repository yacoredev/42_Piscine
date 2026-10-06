/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 20:26:27 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/28 09:31:01 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_result(int *box, int size)
{
	char	c;
	int		i;

	i = 0;
	while (i < size)
	{
		c = box[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	in_same_diagonal(int old_row, int cur_row, int old_col, int cur_col)
{
	int	def_row;
	int	def_col;

	def_row = cur_row - old_row;
	def_col = cur_col - old_col;
	return (def_row == def_col || def_row == -def_col);
}

int	is_valdeplace(int *box, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (box[i] == row || in_same_diagonal(box[i], row, i, col))
			return (0);
		i++;
	}
	return (1);
}

void	generate_sol(int *box, int col, int *count, int size)
{
	int	row;

	if (col == size)
	{
		print_result(box, size);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < size)
	{
		if (is_valdeplace(box, col, row))
		{
			box[col] = row;
			generate_sol(box, col + 1, count, size);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	box[10];
	int	total_sols;

	total_sols = 0;
	generate_sol(box, 0, &total_sols, 10);
	return (total_sols);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("-----------\nTotal solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}
*/
