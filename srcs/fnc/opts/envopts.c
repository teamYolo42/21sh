/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envopts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:12:32 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/15 17:49:40 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

static void			add_options(char *optenv, char *new)
{
    int		i;

    i = 1;
    while (new[i] != '\0')
    {
        if (new[i] == 'i')
            OPT_ENV_I = 1;
        else
            ft_erroru("env","Illegal argument"," env [-i] [key=var..] binany");
        i++;
    }
}

int					get_options_env(char *optenv, char **argv, int argc)
{
    int		i;

    i = 1;
    ft_bzero(optenv, 1);
    while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
    {
        add_options(optenv, argv[i]);
        i++;
    }
    return (i);
}