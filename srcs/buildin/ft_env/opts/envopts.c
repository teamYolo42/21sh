/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envopts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:12:32 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/16 18:18:56 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/21sh.h"

static int			add_options(char *optenv, const char *new)
{
    int		i;

    i = 1;
    while (new[i] != '\0')
    {
        if (new[i] == 'i')
            OPT_ENV_I = 1;
        else
        {
            ft_erroru("env ", "Illegal argument", " env [-i] [key=var..] binany");
            return (-1);
        }
        i++;
    }
    return (1);
}

int					get_options_env(char *optenv, char **argv, int argc)
{
    int		i;

    i = 1;
    ft_bzero(optenv, 1);
    while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
    {
        if (add_options(optenv, argv[i]) == -1)
            return (-1);
        i++;
    }
    return (i);
}