/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:06:52 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 19:06:57 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	find_colon(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ':')
			return (i);
		i++;
	}
	return (-1);
}

char	*trim(char *s)
{
	int	end;
	int	start;

	end = str_len(s) - 1;
	while (end >= 0 && (s[end] == ' ' || s[end] == '\t' || s[end] == '\r'))
	{
		s[end] = '\0';
		end--;
	}
	start = 0;
	while (s[start] == ' ' || s[start] == '\t')
		start++;
	return (s + start);
}

int	is_blank(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	process_line(char *line, t_dict *dict, int *count)
{
	int		colon;
	char	*key_part;
	char	*value_part;
	char	*norm_key;
	int		result;

	if (is_blank(line))
		return (0);
	colon = find_colon(line);
	if (colon == -1)
		return (-1);
	line[colon] = '\0';
	key_part = trim(line);
	value_part = trim(line + colon + 1);
	if (!is_number(key_part))
		return (-1);
	norm_key = decimal_number(key_part);
	if (!norm_key)
		return (-1);
	result = add_entry(dict, count, norm_key, value_part);
	free(norm_key);
	return (result);
}

int	handle_line_end(char *line, t_dict *dict, int *count)
{
	if (process_line(line, dict, count) == -1)
	{
		free_dict(dict, *count);
		return (-1);
	}
	return (0);
}

int	parse_dict(char *buf, t_dict *dict)
{
	char	line[MAX_LINE];
	int		li;
	int		i;
	int		count;

	count = 0;
	li = 0;
	i = 0;
	while (1)
	{
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			line[li] = '\0';
			if (handle_line_end(line, dict, &count) == -1)
				return (-1);
			li = 0;
			if (buf[i] == '\0')
				return (count);
		}
		else if (li < MAX_LINE - 1)
			line[li++] = buf[i];
		i++;
	}
}
