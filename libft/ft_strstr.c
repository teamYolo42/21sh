/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:06:45 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strstr(const char *str, const char *find)
{
	int		i;
	int		j;
	int		k;
	char	*s;
	char	*f;

	i = 0;
	j = 0;
	s = (char *)str;
	f = (char *)find;
	if (!f[i])
		return (s);
	while (s[i])
	{
		j = i;
		k = 0;
		while (s[j++] == f[k++])
			if (!f[k])
				return (&s[i]);
		i++;
	}
	return (NULL);
}
