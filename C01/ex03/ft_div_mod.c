/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 22:32:53 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/17 22:39:23 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
	{
		*div = 0;
		*mod = 0;
		return ;
	}
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int     main()
{
    int a = 45;
    int b = 10;
    int mod;
    int div;
    
    ft_div_mod(a, b, &div, &mod);
        printf("mod = %d\ndiv = %d", mod, div);
}
 */
