/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:06:37 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 19:06:40 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*find_value(t_dict *dict, int count, char *key)
{
	int	index;

	index = find_index(dict, count, key);
	if (index == -1)
		return (NULL);
	return (dict[index].value);
}
