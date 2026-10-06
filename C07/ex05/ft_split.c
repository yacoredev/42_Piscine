/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:49:34 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/31 20:49:47 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *seps)
{
	int	i;

	i = 0;
	while (seps[i] && c != seps[i])
	{
		i++;
	}
	if (seps[i] == '\0')
		return (0);
	return (1);
}

int	ft_wordlen(char *str, int *start, char *seps)
{
	int	len;
	int	i;

	len = 0;
	i = *start;
	while (str[i] && is_sep(str[i], seps))
		i++;
	*start = i;
	while (str[i] && !is_sep(str[i], seps))
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_put_word(int len, int *start, char *str)
{
	int		j;
	int		i;
	char	*ptr;

	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	j = *start;
	while (i < len)
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	*start = j;
	return (ptr);
}

int	ft_count_words(char *str, char *seps)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], seps) && (i == 0 || is_sep(str[i - 1], seps)))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		count_words;
	int		start;
	int		i;

	count_words = ft_count_words(str, charset);
	if (count_words != 0)
	{
		arr = malloc((count_words + 1) * sizeof(char *));
		if (arr == NULL)
			return (NULL);
		start = 0;
		i = 0;
		while (i < count_words)
			arr[i++] = ft_put_word(ft_wordlen(str, &start, charset), &start,
					str);
	}
	else
	{
		arr = malloc(sizeof(char *));
		arr[0] = NULL;
	}
	return (arr);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	char	**arr;

	if (ac == 3)
	{
		arr = ft_split(av[1], av[2]);
		for (int i = 0; arr[i]; i++)
			printf("%s\n", arr[i]);
		if (!*arr)
			printf("NULL");
	}
}
*/
