/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:29:41 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:46:07 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoinc(char *s, char c)
{
	char	*new;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s) + i;
	if (!(new = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	return (new);
}

char	*ft_strjoincfree(char *s, char c)
{
	char	*new;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s) + i;
	if (!(new = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	free(s);
	return (new);
}
