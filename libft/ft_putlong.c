/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:02:23 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_putlong(long nb)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putlong(nb / 10);
		ft_putlong(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
