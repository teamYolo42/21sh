/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:32:21 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/24 18:16:03 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void    ft_puttab(char **tab)
{
    int		i;

    i = 0;
    while (tab[i])
        ft_putendl(tab[i++]);
}

void    ft_puttabd(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putendl(tab[i]);
		i++;
	}
}