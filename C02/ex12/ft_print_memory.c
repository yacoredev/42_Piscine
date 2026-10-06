/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 22:00:36 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/22 20:25:01 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_cnt_printable(char *line, int start, int size)
{
	int	i;

	i = 0;
	while (i < 16 && start + i < size)
	{
		if (line[i] >= ' ' && line[i] <= '~')
			ft_putchar(line[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	print_cnt_hexa(char *text, unsigned int start, unsigned int size)
{
	char			*hexa;
	unsigned int	end;

	hexa = "0123456789abcdef";
	end = start + 16;
	while (start < end)
	{
		if (start < size)
		{
			ft_putchar(hexa[(unsigned char)text[start] / 16]);
			ft_putchar(hexa[(unsigned char)text[start] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (start % 2 != 0)
			ft_putchar(' ');
		start++;
	}
}

void	print_line_address(unsigned long ptr_line)
{
	char	*hexa;
	char	line_addr[17];
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		line_addr[i] = hexa[(long)ptr_line % 16];
		ptr_line /= 16;
		i++;
	}
	line_addr[i] = '\0';
	while (i > 0)
		ft_putchar(line_addr[--i]);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*ptr_to_line;
	int		i;

	ptr_to_line = (char *)addr;
	i = 0;
	while ((unsigned int)i < size)
	{
		print_line_address((unsigned long)ptr_to_line + i);
		print_cnt_hexa(ptr_to_line, i, size);
		print_cnt_printable(ptr_to_line + i, i, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
/*
#include <stdio.h>
int	main(void)
{
        char str[] = "Bonjour les aminches\t\n\tc\t est fou\tto"
		"ut\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
        ft_print_memory(str, sizeof(str));
        
	// char str[] = "This is a simple test for ft_print_memory" 
	// "1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // ft_print_memory(str, sizeof(str) - 1);

	// ft_print_memory(str, 33);
	return (0);
}
*/
