/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:53:18 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*epur_str(char *str)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(str) + 1))))
		return (NULL);
	while ((str[i] == ' ') || (str[i] == '\t'))
		i++;
	while (str[i] != '\0')
	{
		tmp[k++] = str[i++];
		while ((str[i] == ' ') || (str[i] == '\t'))
			i++;
		if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
		{
			tmp[k] = ' ';
			k++;
		}
	}
	tmp[k] = '\0';
	return (tmp);
}

char	*epur_str_free(char *str)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (ft_strlen(str) + 1))))
		return (NULL);
	while ((str[i] == ' ') || (str[i] == '\t'))
		i++;
	while (str[i] != '\0')
	{
		tmp[k++] = str[i++];
		while ((str[i] == ' ') || (str[i] == '\t'))
			i++;
		if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
		{
			tmp[k] = ' ';
			k++;
		}
	}
	tmp[k] = '\0';
	free(str);
	return (tmp);
}
