/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:50:12 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/22 10:22:29 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
        char src[] = "hello";
        char dest[12];

        char *ptr_to_dest = ft_strncpy(dest, src, 4);

	printf("%s", ptr_to_dest);
	return (0);
}
*/
