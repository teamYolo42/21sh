/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:34:23 by pcartau           #+#    #+#             */
/*   Updated: 2018/01/22 14:37:55 by pcartau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "makefile.h"

void	put(char *str)
{
	ft_putmultistr(_Y, str, _RE);
	ft_putchar('\n');
}

int		main(void)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open("Makefile_srcs/compiling", O_RDONLY);
	while (gnl(fd, &str))
		put(str);
	return (0);
}
