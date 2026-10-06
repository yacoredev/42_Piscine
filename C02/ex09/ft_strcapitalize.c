/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 20:32:02 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/21 22:12:15 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_digit(char n)
{
	return (n >= '0' && n <= '9');
}

int	ft_is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

void	ft_charlowcase(char *c)
{
	if (ft_is_upper(*c))
		*c += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_alpha(str[i]))
		{
			ft_charlowcase(&str[i]);
			if (i == 0
				|| (!ft_is_alpha(str[i - 1]) && !ft_is_digit(str[i - 1])))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
