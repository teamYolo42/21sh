/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:51:06 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/27 15:30:47 by asandolo         ###   ########.fr       */
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
//
//void			ft_cd(char ***env, char *str)
//{
//	ft_strcut(str, 2);
//	if (!ft_ispace(str[0]))
//	{
//		if (ft_strcmp(str, "") == 0)
//			ft_cd_nothing(env);
//		else
//		{
//			ft_error("Error: ", "command not found");
//			return ;
//		}
//	}
//	else
//		ft_cd2(env, str);
//}


void			ft_cd(char ***env, char *str)
{
	char **av;
	char *s;
	char *s2;
	int ac;
	int i;
	char optcd[2];

	av = ft_strsplit(str, ' ');
	ac = (int) ft_countwords(str, ' ');
	i = get_options_cd(optcd, av, ac);
	if (i == -1)
	{
		freer(av);
		return;
	}
	if (i == ac)
	{
		ft_cd_nothing(env);
		return ;
	}
	s = ft_joinsplitc(av, i, ' ');
	if(OPT_CD_P)
		ft_cd2(env, s);
	else
	{
		s2 = cd_parse_path(env, s);
		free(s2);
	}
	if (s)
		free(s);
	freer(av);
}

//void			ft_cd(char ***env, char *str)
//{
//	char buf[PATH_MAX];
//	char buf2[PATH_MAX];
//
//	getcwd(buf2, PATH_MAX);
//	ft_putendl(buf2);
//	ft_strcut(str, 2);
//	ft_cutspace(str);
//	chdir(str);
//	getcwd(buf, PATH_MAX);
//	ft_putendl(buf);
//	ft_putendl(str);
//	if(parseenv_env(env, str, "PWD", 1))
//		*env = addenv_env(*env, "PWD", str);
//	if(parseenv_env(env, buf2, "OLDPWD", 1))
//		*env = addenv_env(*env, "OLDPWD", buf2);
//
//}