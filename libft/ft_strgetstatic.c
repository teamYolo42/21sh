/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgetstatic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:10:07 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strgetstatic(char *str, int *next, char c)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = *next;
	k = i;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != c && str[i])
		i++;
	if (!(new = (char *)malloc(sizeof(char) * i - k + 1)))
		return (NULL);
	while (i - k > 0)
	{
		new[j] = str[k];
		j++;
		k++;
	}
	new[j] = '\0';
	*next = i + 1;
	return (new);
}
