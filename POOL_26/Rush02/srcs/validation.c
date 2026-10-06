/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:07:17 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 19:07:19 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_number(char *s)
{
	int	i;

	if (s[0] == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char	*decimal_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '0' && s[i + 1] != '\0')
		i++;
	return (my_strdup(s + i));
}
