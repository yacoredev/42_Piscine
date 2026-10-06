/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:06:06 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 19:06:09 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	str_eq(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (a[i] == '\0' && b[i] == '\0');
}

int	find_index(t_dict *dict, int count, char *key)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (str_eq(dict[i].key, key))
			return (i);
		i++;
	}
	return (-1);
}

int	update_entry(t_dict *dict, int index, char *value)
{
	char	*new_value;

	new_value = my_strdup(value);
	if (!new_value)
		return (-1);
	free(dict[index].value);
	dict[index].value = new_value;
	return (0);
}

int	insert_entry(t_dict *dict, int *count, char *key, char *value)
{
	if (*count >= MAX_DICT)
		return (-1);
	dict[*count].key = my_strdup(key);
	dict[*count].value = my_strdup(value);
	if (!dict[*count].key || !dict[*count].value)
	{
		free(dict[*count].key);
		free(dict[*count].value);
		return (-1);
	}
	*count = *count + 1;
	return (0);
}

int	add_entry(t_dict *dict, int *count, char *key, char *value)
{
	int	index;

	index = find_index(dict, *count, key);
	if (index != -1)
		return (update_entry(dict, index, value));
	return (insert_entry(dict, count, key, value));
}

int	check_base_keys(t_dict *dict, int count)
{
	char	*base[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			"11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "30",
			"40", "50", "60", "70", "80", "90", "100"};
	int		i;

	i = 0;
	while (i < 29)
	{
		if (find_index(dict, count, base[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	check_scale_keys(t_dict *dict, int count)
{
	char	*scale_key;
	int		i;

	i = 3;
	while (i <= 36)
	{
		scale_key = build_scale_key(i);
		if (find_index(dict, count, scale_key) == -1)
		{
			free(scale_key);
			return (0);
		}
		free(scale_key);
		i = i + 3;
	}
	return (1);
}

int	check_keys(t_dict *dict, int count)
{
	if (!check_base_keys(dict, count))
		return (0);
	return (check_scale_keys(dict, count));
}
