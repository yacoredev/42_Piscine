/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:07:44 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 19:07:46 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*my_strdup(char *s)
{
	char	*copy;
	int		i;

	copy = malloc(str_len(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	copy_at(char *dest, int pos, char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[pos + j] = src[j];
		j++;
	}
	return (pos + j);
}

char	*my_join(char *s1, char *sep, char *s2)
{
	char	*result;
	int		pos;

	if (!s1 || !s2)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	result = malloc(str_len(s1) + str_len(sep) + str_len(s2) + 1);
	if (!result)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	pos = copy_at(result, 0, s1);
	pos = copy_at(result, pos, sep);
	pos = copy_at(result, pos, s2);
	result[pos] = '\0';
	free(s1);
	free(s2);
	return (result);
}

char	*int_to_str(int n)
{
	char	buffer[4];
	int		len;
	char	*result;
	int		j;

	len = 0;
	if (n == 0)
		buffer[len++] = '0';
	while (n > 0)
	{
		buffer[len++] = '0' + (n % 10);
		n = n / 10;
	}
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (j < len)
	{
		result[j] = buffer[len - 1 - j];
		j++;
	}
	result[len] = '\0';
	return (result);
}

char	*build_scale_key(int zeros)
{
	char	*result;
	int		i;

	result = malloc(zeros + 2);
	if (!result)
		return (NULL);
	result[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		result[i] = '0';
		i++;
	}
	result[i] = '\0';
	return (result);
}
