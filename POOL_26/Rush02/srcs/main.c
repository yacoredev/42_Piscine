/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:06:45 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 19:06:47 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_str(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
	return (0);
}

int	get_args(int argc, char **argv, char **dict_name, char **value_arg)
{
	if (argc == 2)
	{
		*dict_name = "numbers.dict";
		*value_arg = argv[1];
	}
	else if (argc == 3)
	{
		*dict_name = argv[1];
		*value_arg = argv[2];
	}
	else
		return (0);
	return (is_number(*value_arg));
}

int	load_dict(char *dict_name, t_dict *dict)
{
	char	*file_content;
	int		count;

	file_content = read_file(dict_name);
	if (!file_content)
		return (-1);
	count = parse_dict(file_content, dict);
	free(file_content);
	if (count == -1)
		return (-1);
	if (!check_keys(dict, count))
	{
		free_dict(dict, count);
		return (-1);
	}
	return (count);
}

int	build_result(char *dict_name, char *number, char **result)
{
	t_dict	dict[MAX_DICT];
	int		count;
	int		error;

	count = load_dict(dict_name, dict);
	if (count == -1)
		return (-1);
	error = 0;
	*result = convert(number, dict, count, &error);
	free_dict(dict, count);
	if (error || !*result)
	{
		free(*result);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dict_name;
	char	*value_arg;
	char	*number;
	char	*result;

	if (!get_args(argc, argv, &dict_name, &value_arg))
		return (print_str("Error"));
	number = decimal_number(value_arg);
	if (!number)
		return (print_str("Error"));
	if (build_result(dict_name, number, &result) == -1)
	{
		free(number);
		return (print_str("Dict Error"));
	}
	free(number);
	print_str(result);
	free(result);
	return (0);
}
