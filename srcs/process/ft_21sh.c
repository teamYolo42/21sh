/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:04:13 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/15 14:50:23 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

void				freer(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static	void		go2(char ***env, char ***cenv,  char *buf)
{
	if (ft_strnstr(buf, "exit", 4))
		ft_putstr("");
	else if (ft_strnstr(buf, "echo", 5))
		ft_echo(cenv, buf);
	else if (ft_strnstr(buf, "cd", 2))
		ft_putstr("");
	else if (ft_strnstr(buf, "env", 3))
		ft_env(cenv, buf);
	else if (ft_strnstr(buf, "setenv ", 7))
		ft_putstr("");
	else if (ft_strnstr(buf, "unsetenv ", 9))
		ft_putstr("");
	else if (ft_strcmp(buf, "") != 0)
		ft_exec(env, cenv, buf);
}

void				go(char ***env, char ***cenv, char *buf, int m)
{
	ft_cutspace(buf);
	ft_replacechar(buf, '\t', ' ');
	if (m == 0)
	{
		if (ft_strnstr(buf, "exit", 4))
			ft_exit(buf);
		else if (ft_strnstr(buf, "echo", 5))
			ft_echo(cenv, buf);
		else if (ft_strnstr(buf, "cd", 2))
			ft_cd(cenv, buf);
		else if (ft_strnstr(buf, "env", 3))
			ft_env(cenv, buf);
		else if (ft_strnstr(buf, "setenv ", 7))
			ft_setenv(buf, 0);
		else if (ft_strnstr(buf, "unsetenv ", 9))
			ft_unsetenv(buf, 0);
		else if (ft_strcmp(buf, "") != 0)
			ft_exec(env, cenv, buf);
	}
	else
		go2(env, cenv,  buf);
	g_pid = 0;
}

static	int			reader(void)
{
	char	*buf;
	char	**str;
	int		i;

	i = -1;
	buf = ft_strnew(4096);
	read(0, buf, 4096);
	ft_delchar(buf, 13);
	ft_delchar(buf, 10);
	str = ft_strsplit(buf, ';');
	while (str[++i])
		go(&g_env, &g_env,  str[i], 0);
	freer(str);
	free(buf);
	return (1);
}

void				ft_21sh(char **envi)
{
	g_env = ft_strdupdup(envi);
	ft_starting();
	ft_affprompt();
	while (reader())
		ft_affprompt();
}
