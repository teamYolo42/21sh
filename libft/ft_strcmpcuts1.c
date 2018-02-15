/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpcuts1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:26:50 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strcmpcuts1(char *s1, char *s2, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j] && s1[i] == s2[j] && s1[j] != c)
	{
		i++;
		j++;
	}
	if (s1[j] == c)
	{
		while (s2[i])
			i++;
		i--;
	}
	return (s1[j - 1] - s2[i]);
}
