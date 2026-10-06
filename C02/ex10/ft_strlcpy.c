/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 22:44:59 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/21 22:14:08 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		src_len;
	unsigned int		i;

	src_len = ft_strlen(src);
	i = 0;
	if (size)
	{
		while (*src && i < size - 1)
		{
			*dest = *src;
			dest++;
			src++;
			i++;
		}
		*dest = '\0';
	}
	return (src_len);
}
/*
#include <stdio.h>
int main()
{
	unsigned int sizeDest = 4;

	char src[] = "hello";
	char dest[sizeDest];

	unsigned int lenSrc = ft_strlcpy(dest, src, sizeDest);

	printf("%s\n", dest);

	if (lenSrc < sizeDest)
		printf("%d chars successfully copied\n", lenSrc);

	else if (lenSrc >= sizeDest)
		printf("truncation happened\n");

	return(0);
}
*/
