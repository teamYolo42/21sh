/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:27:20 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_cut(char *name, char c)
{
	size_t i;
	size_t j;

	i = ft_strlen(name);
	while (name[i] != c)
		i--;
	i++;
	j = 0;
	while (name[i])
	{
		name[j] = name[i];
		i++;
		j++;
	}
	name[j] = '\0';
	return (name);
}
