/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:15:07 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/15 19:04:35 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

static void			put_env(const char *optenv, char **env, char *str, int m)
{
    char **ss;
	
    if (m == 0)
    {
        if (OPT_ENV_I)
            ft_putstr("");
        else
		{
			if (env)
				ft_puttab(env);
		}
    }
    else
    {
        if (OPT_ENV_I)
        {
            ss = ft_strsplit(str, ' ');
            ft_puttab(ss);
            freer(ss);
        }
        else
        {
            ft_puttab(env);
            ss = ft_strsplit(str, ' ');
            ft_puttab(ss);
            freer(ss);
        }
    }
}

static char    *ft_joinsplit(char **split, int i)
{
    char *ret;

    ret = ft_strdup(split[i]);
    while (split[i] && split[i + 1])
    {
        ret = ft_strjoincfree(ret, ' ');
        ret = ft_strjoinfrees1(ret, split[i + 1]);
        i++;
    }
    return (ret);
}

static	void		ft_env2(char *str, int m)
{
	char	**env;
	char	**split;
	int		i;
	char	*tmp;

	i = 0;
    if (m == 0)
	    env = ft_strdupdup(g_env);
    else
        env = 0;
	split = ft_strsplit(str, ' ');
	ft_puttab(split);
	while (split[i] && ft_setenv_env(&env, split[i]) == 0)
		i++;
	ft_putendl(split[i]);
	if (split[i])
	{
		tmp = ft_joinsplit(split, i);
		ft_putendl(tmp);
		go(&g_env, &env, tmp, 1);
		free(tmp);
	}
    if (env)
	    freer(env);
	freer(split);
}

int     ft_ckeckmode(char **split, int i)
{
    while (split[i])
    {
        if (checksyntax_env(split[i]) != -1)
            return (1);
        i++;
    }
    return (0);
}

void    ft_env(char ***env, char *str)
{
    int     i;
    char    **av;
    char    optenv[1];
    int     ac;
    char    *s;

    s = NULL;
    av = ft_strsplit(str, ' ');
    ac = (int) ft_countwords(str, ' ');
    i = get_options_env(optenv, av, ac);
    if (i == ac)
	{
		if (env)
			put_env(optenv, *env, s, 0);
    }
	else
    {
        ac = ft_ckeckmode(av, i);
        s = ft_joinsplit(av, i);
        if(ac == 1)
        {
            if (OPT_ENV_I)
                ft_env2(s, 1);
            else
                ft_env2(s, 0);
        }
        else
		{
			if (env)
				 put_env(optenv, *env, s, 1);
        }
		free(s);
    }
    freer(av);
}
