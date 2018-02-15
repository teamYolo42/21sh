/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupplus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:11:59 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:45:27 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

char	**ft_strdupdup_plus(char **str, int p)
{
	int		i;
	int		tmp;
	char	**n;

	i = 0;
	while (str[i])
		i++;
	tmp = i + p;
	if (!(n = malloc(sizeof(char *) * (tmp + 1))))
		return (NULL);
	i = 0;
	while (i < tmp)
	{
		if (str[i] && i < 31)
			n[i] = ft_strdup(str[i]);
		else
			n[i] = ft_strnew(1);
		i++;
	}
	n[i] = 0;
	return (n);
}
