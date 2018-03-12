/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:51:06 by asandolo          #+#    #+#             */
/*   Updated: 2018/03/09 14:26:41 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

static void ft_cd_point(char ***env)
{
	t_vatcdt v;
	char buf[PATH_MAX];

	v.oldpwd = ft_getenv(env, "OLDPWD");
	v.pwd   = getcwd(buf, PATH_MAX);
	cd_change_env(env, v.pwd, v.oldpwd, 1);
}

static void		ft_cd2(char ***env, char *str)
{
	t_vcdn v;

	ft_delspace(str);
	if (ft_strcmp(str, "") == 0)
		ft_cd_nothing(env);
	else if (ft_strcmp(str, "-") == 0)
		ft_cd_tiret(env);
	else if (ft_strcmp(str, ".") == 0)
		ft_cd_point(env);
	else if (ft_strcmp(str, "/") == 0)
		ft_cd_slash(env);
	else
	{
		v.m = (str[0] == '/') ? 1 : 0;
		v.split = ft_strsplit(str, '/');
		if (testcd(v.split, v.m, getcwd(v.buf, 2048)))
			ft_cd_norm(env, v.split, v.m);
		freer(v.split);
	}
}

void			ft_cd_nor(char ***env, t_cdd v, const char *optcd)
{
	if (OPT_CD_P)
		ft_cd2(env, v.s);
	else
	{
		if (ft_strcmp(v.s, "-") == 0)
			ft_cd_tiret(env);
		else if (ft_strcmp(v.s, ".") == 0)
			ft_cd_point(env);
		else if (ft_strcmp(v.s, "/") == 0)
			ft_cd_slash(env);
		else
		{
			if (testcd2(v.s))
			{
				v.pwd = ft_getenv(env, "PWD");
				v.s2 = cd_parse_path(env, v.s);
				if (v.s2 != NULL)
				{
					chdir(v.s2);
					cd_change_env(env, v.s2, v.pwd, 0);
				}
				else
				{
					free(v.pwd);
					ft_cd_slash(env);
				}

			}

		}
	}
}

void			ft_cd(char ***env, char *str)
{
	t_cdd	v;
	char	optcd[2];


	v.av = ft_strsplit(str, ' ');
	if(!ft_checkcmd("cd", v.av[0]))
	{
		freer(v.av);
		return;
	}
	v.ac = (int) ft_countwords(str, ' ');
	v.i = get_options_cd(optcd, v.av, v.ac);
	if (v.i == -1)
	{
		freer(v.av);
		return;
	}
	if (v.i == v.ac)
	{
		freer(v.av);
		ft_cd_nothing(env);
		return ;
	}
	v.s = ft_joinsplitc(v.av, v.i, ' ');
	ft_cd_nor(env, v, optcd);
	if (v.s)
		free(v.s);;
	freer(v.av);
}