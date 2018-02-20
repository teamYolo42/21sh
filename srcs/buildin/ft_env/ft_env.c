/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:15:07 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/20 15:51:21 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

static void			put_env(const char *optenv, char **env, char *str, int m)
{
    char **ss;
	
    if (m == 0)
    {
        if (OPT_ENV_I)
            ft_putstr("");
        else
			if (env)
				ft_puttab(env);
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
            ss = ft_strsplit(str, ' ');
            ft_put_merge_env(env, ss);
            freer(ss);
        }
    }
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
	while (split[i] && ft_setenv_env(&env, split[i]) == 0)
		i++;
	if (split[i])
	{
		tmp = ft_joinsplitc(split, i, ' ');
		go(&g_env, &env, tmp, 1);
		free(tmp);
	}
    if (env)
	    freer(env);
	freer(split);
}

static int     ft_ckeckmode(char **split, int i)
{
    while (split[i])
    {
        if (checksyntax_env(split[i]) != -1)
            return (1);
        i++;
    }
    return (0);
}


static  void    ft_env_norm(char **av, char *optenv, char ***env, int i)
{
    char    *s;
    int     c;

    c = ft_ckeckmode(av, i);
    s = ft_joinsplitc(av, i, ' ');
    if(c == 1)
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

void    ft_env(char ***env, char *str)
{
    int     i;
    char    **av;
    char    optenv[1];
    int     ac;

    av = ft_strsplit(str, ' ');
    if (!ft_checkcmd(av[0], "env"))
    {
        freer(av);
        return ;
    }
    ac = (int) ft_countwords(str, ' ');
    i = get_options_env(optenv, av, ac);
    if (i == -1)
    {
        freer(av);
        return ;
    }
    if (i == ac)
	{
		if (env)
			put_env(optenv, *env, NULL, 0);
    }
	else
        ft_env_norm(av, optenv, env, i);
    freer(av);
}
