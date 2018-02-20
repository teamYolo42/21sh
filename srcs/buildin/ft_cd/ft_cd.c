/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:51:06 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 13:11:05 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

static void		ft_cd2(char ***env, char *str)
{
	t_vcdn v;

	ft_delspace(str);
	if (ft_strcmp(str, "") == 0)
		ft_cd_nothing(env);
	else if (ft_strcmp(str, "-") == 0)
		ft_cd_tiret(env);
	else if (ft_strcmp(str, ".") == 0)
		return ;
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

void			ft_cd(char ***env, char *str)
{
	ft_strcut(str, 2);
	if (!ft_ispace(str[0]))
	{
		if (ft_strcmp(str, "") == 0)
			ft_cd_nothing(env);
		else
		{
			ft_error("Error: ", "command not found");
			return ;
		}
	}
	else
		ft_cd2(env, str);
}
