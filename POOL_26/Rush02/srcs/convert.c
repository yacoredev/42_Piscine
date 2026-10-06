/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:05:59 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 19:06:01 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*convert_units(int value, t_dict *dict, int count, int *error)
{
	char	*key;
	char	*word;

	key = int_to_str(value);
	word = find_value(dict, count, key);
	free(key);
	if (!word)
	{
		*error = 1;
		return (NULL);
	}
	return (my_strdup(word));
}

char	*convert_tens(int value, t_dict *dict, int count, int *error)
{
	int		tens;
	int		ones;
	char	*key;
	char	*word;

	tens = value - (value % 10);
	ones = value % 10;
	key = int_to_str(tens);
	word = find_value(dict, count, key);
	free(key);
	if (!word)
	{
		*error = 1;
		return (NULL);
	}
	if (ones == 0)
		return (my_strdup(word));
	return (my_join(my_strdup(word), " ", convert_units(ones, dict, count,
				error)));
}

char	*convert_hundreds(int value, t_dict *dict, int count, int *error)
{
	int		hundreds;
	int		rest;
	char	*word;
	char	*result;

	hundreds = value / 100;
	rest = value % 100;
	word = find_value(dict, count, "100");
	if (!word)
	{
		*error = 1;
		return (NULL);
	}
	result = my_join(convert_units(hundreds, dict, count, error), " ",
			my_strdup(word));
	if (rest > 0)
		result = my_join(result, " ", convert_group(rest, dict, count, error));
	return (result);
}

char	*convert_group(int value, t_dict *dict, int count, int *error)
{
	if (value < 20)
		return (convert_units(value, dict, count, error));
	if (value < 100)
		return (convert_tens(value, dict, count, error));
	return (convert_hundreds(value, dict, count, error));
}

int	extract_group(char *number, int start, int length)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	while (i < length)
	{
		value = value * 10 + (number[start + i] - '0');
		i++;
	}
	return (value);
}

char	*add_scale(char *words, int power, t_dict *dict, int count, int *error)
{
	char	*key;
	char	*word;

	if (power == 0)
		return (words);
	key = build_scale_key(power);
	word = find_value(dict, count, key);
	free(key);
	if (!word)
	{
		*error = 1;
		free(words);
		return (NULL);
	}
	return (my_join(words, " ", my_strdup(word)));
}

int	group_bounds(int i, int first_len, int *length)
{
	if (i == 0)
	{
		*length = first_len;
		return (0);
	}
	*length = 3;
	return (first_len + (i - 1) * 3);
}

char	*handle_group(char *result, char *number, int i, int groups,
		int first_len, t_dict *dict, int count, int *error)
{
	int		start;
	int		length;
	int		value;
	char	*words;

	start = group_bounds(i, first_len, &length);
	value = extract_group(number, start, length);
	if (value == 0)
		return (result);
	words = add_scale(convert_group(value, dict, count, error), (groups - 1 - i)
			* 3, dict, count, error);
	if (result == NULL)
		return (words);
	return (my_join(result, " ", words));
}

char	*convert(char *number, t_dict *dict, int count, int *error)
{
	int		len;
	int		groups;
	int		first_len;
	int		i;
	char	*result;

	len = str_len(number);
	if (len == 1 && number[0] == '0')
		return (convert_units(0, dict, count, error));
	groups = (len + 2) / 3;
	first_len = len - (groups - 1) * 3;
	result = NULL;
	i = 0;
	while (i < groups && !(*error))
	{
		result = handle_group(result, number, i, groups, first_len, dict, count,
				error);
		i++;
	}
	return (result);
}
