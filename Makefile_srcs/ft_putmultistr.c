/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmultistr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:36:59 by pcartau           #+#    #+#             */
/*   Updated: 2018/02/15 15:57:22 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "makefile.h"

void	ft_putmultistr(char *s1, char *s2, char *s3)
{
	int i;

	i = -1;
	if (s1)
		while (s1[++i])
			write(1, &s1[i], 1);
	i = -1;
	if (s2)
		while (s2[++i])
			write(1, &s2[i], 1);
	i = -1;
	if (s3)
		while (s3[++i])
			write(1, &s3[i], 1);
}
