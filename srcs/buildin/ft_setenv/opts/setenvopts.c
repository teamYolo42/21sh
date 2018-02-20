/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenvopts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:42:59 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/20 18:01:26 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/21sh.h"

static int			add_options(char *optsetenv, const char *new)
{
    int		i;

    i = 1;
    while (new[i] != '\0')
    {
        if (new[i] == '1')
            OPT_SETENV_1 = 1;
        else
        {
            ft_erroru("setenv ", "Illegal argument", " setenv [-1] [name]=[value]");
            return (-1);
        }
        i++;
    }
    return (1);
}

int					get_options_setenv(char *optsetenv, char **argv, int argc)
{
    int		i;

    i = 1;
    ft_bzero(optsetenv, 1);
    while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
    {
        if (add_options(optsetenv, argv[i]) == -1)
            return (-1);
        i++;
    }
    return (i);
}