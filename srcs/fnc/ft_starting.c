/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:42:40 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/21 12:10:21 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

static  void    ft_start(void)
{
    char *pwd;
    char *oldpwd;
    char buf[PATH_MAX];

    pwd = ft_getenv(&g_env, "PWD");
    oldpwd = ft_getenv(&g_env, "OLDPWD");
    if (!pwd)
        g_env = addenv("PWD", getcwd(buf, PATH_MAX));
    if (!oldpwd)
        g_env = addenv("OLDPWD", getcwd(buf, PATH_MAX));
    if (pwd)
        free(pwd);
    if (oldpwd)
        free(oldpwd);
}

static  void ddfree(char *s1, char *s2)
{
    free(s1);
    free(s2);
}

void	ft_starting(void)
{
	char	*lvl;
    char    *shell;
    char    *c;
	int		ilvl;
    char    buf[2048];

    ft_start();
	lvl = ft_getenv(&g_env, "SHLVL");
    shell = getcwd(buf, 2048);
    c = ft_getenv(&g_env, "SHELL");
	if (lvl)
	{
		ilvl = ft_atoi(lvl);
		ilvl++;
		free(lvl);
		lvl = ft_itoa(ilvl);
		g_env = fillenv("SHLVL", lvl, find_env_var(g_env, "SHLVL"));
		free(lvl);
	}
    if (c)
    {
        shell = ft_strjoinc(shell, '/');
        shell = ft_strjoinfrees1(shell, "./21sh");
        g_env = fillenv("SHELL", shell, find_env_var(g_env, "SHELL"));
        ddfree(shell, c);
    }
}
