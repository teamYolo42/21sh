/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:17:06 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:45:27 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

int		ft_ispace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_cutspace(char *str)
{
	int i;

	i = 0;
	while (ft_ispace(str[i]))
		i++;
	if (i > 0)
		ft_strcut(str, i);
}

void	ft_delspace(char *str)
{
	ft_delchar(str, ' ');
	ft_delchar(str, '\t');
}
