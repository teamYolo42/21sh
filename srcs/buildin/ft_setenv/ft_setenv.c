/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:40:29 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/20 18:24:04 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"



static	int		checksyntax(const char *str)
{
    int		i;

    i = 0;
    while (str[i] != ' ' && str[i] != '=' && str[i])
        i++;
    if (str[i] == '=')
    {
        i++;
        if (!str[i])
            return (0);
        while (str[i])
            i++;
        if (!str[i])
            return (1);
    }
    else
        return (0);
    return (0);
}

static  void    ft_setenv_norm(char **av, const char *optsetenv, int i)
{
    char *s;
    char *name;
    char *value;

    s = ft_joinsplitc(av, i, ' ');
    if(checksyntax(s))
    {
        name = ft_strgetchartc(s, '=');
        value = ft_cut(s, '=');
        if (OPT_SETENV_1)
        {
            if (parseenv(value, name, 1))
                g_env = addenv(name, value);
        }
        else
        {
            if (parseenv(value, name, 0))
                g_env = addenv(name, value);
        }

    }
    else
        ft_erroru("setenv ", "Syntax error ", " setenv [-1] [name]=[value]");
    free(s);
}

void			ft_setenv(char *str, int m)
{
    t_setenv v;

    v.i = 0;
    v.ac = 0;
    v.av = ft_strsplit(str, ' ');
    if (m == 0)
    {
        if (!ft_checkcmd(v.av[0], "setenv"))
        {
            freer(v.av);
            return ;
        }
        v.ac = (int) ft_countwords(str, ' ');
        v.i = get_options_setenv(v.optsetenv, v.av, v.ac);
        if (v.i == -1)
        {
            freer(v.av);
            return ;
        }
    }
    if (v.i == v.ac)
        ft_erroru("setenv ", "Syntax Error ", " setenv [-1] [name]=[value]");
    else
        ft_setenv_norm(v.av, v.optsetenv, v.i);
    freer(v.av);
}