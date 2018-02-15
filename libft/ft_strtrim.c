/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:48:40 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtrim(char const *s)
{
	int		st;
	int		e;

	if (!s)
		return (NULL);
	e = ft_strlen((char *)s) - 1;
	st = 0;
	while (s[st] && (s[st] == '\n' || s[st] == '\t' || s[st] == ' '))
		st++;
	while (s[e] && (s[e] == '\n' || s[e] == '\t' || s[e] == ' ')
	&& e > st)
		e--;
	return (ft_strsub(s, st, (e - st + 1)));
}
