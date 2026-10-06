/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:24:36 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/29 18:40:30 by yabaadi          ###   ########.fr       */
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

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}

int	ft_len_words(char **strs, int size)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (*(*(strs + i) + j))
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

void	ft_putstr(char *buff, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(buff, *(strs + i));
		if (i < size - 1)
			ft_strcat(buff, sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*all;
	int		len_words;
	int		all_size;

	if (size > 0)
	{
		len_words = ft_len_words(strs, size);
		all_size = (len_words + ((size - 1) * ft_strlen(sep)));
		all = malloc((all_size + 1) * sizeof(char));
		if (!all)
			return (NULL);
		*all = '\0';
		ft_putstr(all, strs, sep, size);
	}
	else
	{
		all = malloc(1);
		if (!all)
			return (NULL);
		*all = '\0';
	}
	return (all);
}
/*
#include <stdio.h>
int	main()
{
	char	*strs[] = {"hello", "world", "life", "drive"};
	char	*sep = ":)";
	char	*result;
	int	size;

	size = sizeof(strs) / sizeof(strs[0]);
	result = ft_strjoin(size, strs, sep);
	printf("%s\n", result);
		
	free(result);
}
*/