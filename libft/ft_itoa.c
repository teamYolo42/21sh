/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:37:24 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_intlen(int n)
{
	int i;

	i = (ft_isnegativ(n)) ? 2 : 1;
	while (n /= 10)
		i++;
	return (i);
}

static long	ft_longlen(long n)
{
	long i;

	i = (ft_isnegativ(n)) ? 2 : 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		cpy;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cpy = n;
	len = ft_intlen(n);
	if (ft_isnegativ(n))
		cpy = -n;
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	len--;
	while (len >= 0)
	{
		ret[len--] = '0' + cpy % 10;
		cpy = cpy / 10;
	}
	if (ft_isnegativ(n))
		ret[0] = '-';
	return (ret);
}

char		*ft_ltoa(long n)
{
	char		*ret;
	long		len;
	long		cpy;

	cpy = n;
	len = ft_longlen(n);
	if (n < 0)
		cpy = -n;
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	len--;
	while (len >= 0)
	{
		ret[len--] = '0' + cpy % 10;
		cpy = cpy / 10;
	}
	if (ft_isnegativ(n))
		ret[0] = '-';
	return (ret);
}
