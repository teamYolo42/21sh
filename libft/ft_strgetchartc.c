/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgetchartc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:19:51 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strgetchartc(char *str, char c)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i])
	{
		j = 0;
		if (!(new = malloc(sizeof(char) * (ft_strlen(str) - i + 1))))
			return (NULL);
		while (j < i)
		{
			new[j] = str[j];
			j++;
		}
		new[j] = '\0';
	}
	else
		return (NULL);
	return (new);
}

char	*ft_strgetchartc_nm(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i])
	{
		str[i] = '\0';
		new = ft_strdup(str);
		free(str);
		return (new);
	}
	return (str);
}
