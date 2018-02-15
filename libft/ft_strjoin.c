/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:33:47 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/09 10:52:29 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;
	size_t	n;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	n = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * n + 1);
	if (s == NULL)
		return (0);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

static void	ffree(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char		*ft_strjoinfree(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;
	size_t	n;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = -1;
	n = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * n + 1);
	if (s == NULL)
		return (0);
	while (s1[++i])
		s[i] = s1[i];
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	ffree(s1, s2);
	return (s);
}

char		*ft_strjoinfrees1(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;
	size_t	n;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = -1;
	n = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * n + 1);
	if (s == NULL)
		return (0);
	while (s1[++i])
		s[i] = s1[i];
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	free(s1);
	return (s);
}

char		*ft_strjoinfrees2(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;
	size_t	n;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = -1;
	n = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * n + 1);
	if (s == NULL)
		return (0);
	while (s1[++i])
		s[i] = s1[i];
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	free(s2);
	return (s);
}
