/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdopts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:04:31 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/24 12:35:40 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/21sh.h"

static int			add_options(char *optcd, const char *new)
{
	int		i;

	i = 1;
	while (new[i] != '\0')
	{
		if (new[i] == 'P')
			OPT_CD_P = 1;
		else if (new[i] == 'L')
			OPT_CD_L = 1;
		else
		{
			ft_erroru("cd: ", "Illegal argument ", " cd [-P|-L] [args...]");
			return (-1);
		}
		i++;
	}
	return (1);
}

int					get_options_cd(char *optcd, char **argv, int argc)
{
	int		i;

	i = 1;
	ft_bzero(optcd, 1);
	while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
	{
		if (add_options(optcd, argv[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}