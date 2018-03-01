/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:53:49 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:45:22 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

void			*ft_reallocd(char **ptr, int size, char *newstr)
{
	char	**newptr;
	int		i;

	i = 0;
	if (!(newptr = (char **)malloc(sizeof(char *) *
		(ft_tablen(ptr) + size + 1))))
		return (NULL);
	while (i < ft_tablen(ptr) + size)
	{
		if (i < ft_tablen(ptr))
			newptr[i] = ptr[i];
		else
			newptr[i] = ft_strdup(newstr);
		i++;
	}
	newptr[i] = 0;
	free(ptr);
	return (newptr);
}
