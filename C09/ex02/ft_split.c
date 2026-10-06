/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:45:15 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/03 16:45:16 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char *seps, char c)
{
	while (*seps)
	{
		if (*seps == c)
			return (1);
		seps++;
	}
	return (0);
}

int	ft_count_words(char *str, char *seps)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(seps, *str))
			str++;
		if (*str)
		{
			count++;
			while (*str && !is_sep(seps, *str))
				str++;
		}
	}
	return (count);
}

char	*sub_string(char *str, int *i, char *seps)
{
	int		start;
	int		end;
	char	*sub_str;
	char	*tmp;

	while (str[*i] && is_sep(seps, str[*i]))
		(*i)++;
	start = *i;
	while (str[*i] && !is_sep(seps, str[*i]))
		(*i)++;
	end = (*i) - 1;
	sub_str = malloc((end - start + 2) * sizeof(char));
	tmp = sub_str;
	if (!sub_str)
		return (NULL);
	while (start <= end)
		*sub_str++ = str[start++];
	*sub_str = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	char	**tmp;
	int		count_words;
	int		i;

	count_words = ft_count_words(str, charset);
	arr = malloc((count_words + 1) * sizeof(char *));
	tmp = arr;
	if (!arr)
		return (NULL);
	i = 0;
	while (count_words > 0)
	{
		*arr++ = sub_string(str, &i, charset);
		count_words--;
	}
	*arr = NULL;
	return (tmp);
}
/*
#include <unistd.h>

int	main(int ac, char **av)
{
	char	**array;

	int     i, j;
	if (ac > 1)
	{
		array = ft_split(av[1], av[2]);
		// if (*array == NULL)
		//     printf("NULL\n");
		i = 0;
		while (array[i])
		{
			j = 0;
			while (array[i][j])
			{
				write(1, &array[i][j], 1);
				j++;
			}
			if (array[i+1] != NULL)
				write(1, "\n", 1);
			i++;
		}
	}
}
*/