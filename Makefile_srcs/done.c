/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:34:05 by pcartau           #+#    #+#             */
/*   Updated: 2018/01/22 14:37:31 by pcartau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "makefile.h"

void	put(char *str)
{
	ft_putmultistr(_G, str, _0);
	ft_putchar('\n');
}

int		main(void)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open("Makefile_srcs/done", O_RDONLY);
	while (gnl(fd, &str))
		put(str);
	return (0);
}
