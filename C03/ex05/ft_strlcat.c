/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 00:43:25 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/23 10:12:16 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	i = 0;
	while (src[i] && (dst_len + i) < size - 1)
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (src_len + dst_len);
}
/*
#include <stdio.h> 
int main(int argc, char *argv[]) 
{
	char buffer[20] = "origin text."; 
	unsigned int size = sizeof(buffer); 
	unsigned int ret_len; 

	if (argc == 2) 
	{
			ret_len = ft_strlcat(buffer, argv[1], size); 

			printf("result: %s\n", buffer); 
			printf("The length of string that tried to create: %d\n", ret_len); 
			printf("Buffer size allowed: %d\n", size); 

		// TRUNCATION CHECK 
		if (ret_len < size) 
			printf("\nCopying successful\n"); 
		else 
		{
			printf("\nTruncation happened\n"); 
			printf("you need at least %d bytes\n", ret_len); 
		} 
	} 
	else
	{ 
		printf("put one string to catenate it with origin text!\n"); 
	}
	return (0); 
}
*/