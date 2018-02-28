/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removefromtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:21:01 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/28 17:36:31 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_tabl(char **arr)
{
	int		i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

static char		**copy_tab_w(int rem, char **new_arr, char **arr, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != rem)
		{
			if (!(new_arr[j] = (char*)malloc(sizeof(char) * (ft_strlen(arr[i]) + 1))))
				return (NULL);
			if (new_arr[j])
			{
				ft_strcpy(new_arr[j], arr[i]);
				j++;
			}
		}
		i++;
	}
	freer(arr);
	new_arr[j] = 0;
	return (new_arr);
}

char		**ft_removefromtab(char **arr, int rem)
{
	int		len;
	char		**new_arr;

	new_arr = NULL;
	if (arr != NULL)
	{
		len = ft_tabl(arr);
		new_arr = (char**)malloc(sizeof(char*) * (len));
		new_arr = copy_tab_w(rem, new_arr, arr, len);
	}
	return (new_arr);
}


static char		**copy_tab_w2(int rem, char **new_arr, char **arr, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != rem && i != rem - 1)
		{
			if (!(new_arr[j] = (char*)malloc(sizeof(char) * (ft_strlen(arr[i]) + 1))))
				return (NULL);
			if (new_arr[j])
			{
				ft_strcpy(new_arr[j], arr[i]);
				j++;
			}
		}
		i++;
	}
	freer(arr);
	new_arr[j] = NULL;
	return (new_arr);
}

char		**ft_removefromtab2(char **arr, int rem)
{
	int		len;
	char		**new_arr;

	new_arr = NULL;
	if (arr)
	{
		len = ft_tabl(arr);
		new_arr = (char**)malloc(sizeof(char*) * (len + 1));
		new_arr = copy_tab_w2(rem, new_arr, arr, len);
	}
	return (new_arr);
}