/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:00:54 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/29 10:42:13 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen(src);
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "hello world";
	char	*copy_heap;

	copy_heap = ft_strdup(str);
	printf("%s\n", copy_heap);
	free(copy_heap);
	return (0);
}
*/