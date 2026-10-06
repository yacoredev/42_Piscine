/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 20:06:09 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/22 10:42:04 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

int	ft_str_is_printable(char *str)
{
	int	i;

	if (*str == '\0')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_is_printable(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
        printf("%d", ft_str_is_printable("hell\no"));
}
*/
