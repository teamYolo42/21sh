/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:53:46 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:45:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_array_length(char **arr)
{
	int		i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i] != NULL)
		i = i + 1;
	return (i);
}

char			**ft_strdupdup(char **str)
{
	char	**new_array;
	int		len;
	int		str_len;
	int		i;

	len = ft_array_length(str);
	new_array = (char**)malloc(sizeof(char*) * (len + 1));
	if (new_array != NULL)
	{
		i = 0;
		while (i < len)
		{
			str_len = ft_strlen(str[i]);
			new_array[i] = (char*)malloc(sizeof(char) * (str_len + 1));
			if (new_array[i] != NULL)
				ft_strcpy(new_array[i], str[i]);
			i = i + 1;
		}
		new_array[i] = NULL;
	}
	return (new_array);
}
