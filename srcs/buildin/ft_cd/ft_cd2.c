/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:51:06 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/16 17:11:06 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

void		ft_cd_tiret(char ***env)
{
	t_vatcdt v;

	v.pwd = ft_getenv(env, "PWD");
    if (!v.pwd)
        return ;
	v.oldpwd = ft_getenv(env, "OLDPWD");
    if (!v.oldpwd)
    {
        free(v.pwd);
        ft_error("cd: ","OLDPWD NOT SET");
        return ;
    }
	*env = fillenv("PWD", v.oldpwd, find_env_var(*env, "PWD"));
	*env = fillenv("OLDPWD", v.pwd, find_env_var(*env, "OLDPWD"));
	free(v.pwd);
	ft_putendl(v.oldpwd);
	chdir(v.oldpwd);
	free(v.oldpwd);
}

void		ft_cd_nothing(char ***env)
{
	t_vatcdt v;

	v.pwd = ft_getenv(env, "PWD");
    if (!v.pwd)
        return ;
	v.home = ft_getenv(env, "HOME");
    if (!v.home)
    {
        free(v.pwd);
        ft_error("cd: ","HOME PATH neot set");
        return;
    }
	*env = fillenv("PWD", v.home, find_env_var(*env, "PWD"));
	*env = fillenv("OLDPWD", v.pwd, find_env_var(*env, "OLDPWD"));
	free(v.pwd);
	free(v.home);
	chdir(v.home);
}

void		ft_cd_norm(char ***env, char **str, int m)
{
	char		buf[PATH_MAX];
	t_vatcdt	v;
	int			i;

    v.pwd = ft_getenv(env, "PWD");
    if (!v.pwd)
        return ;
	i = 0;
	if (m)
		chdir("/");
	if (ft_strcmp(str[i], "~") == 0)
	{
		ft_cd_nothing(env);
		i++;
	}
	while (str[i])
		chdir(str[i++]);
	v.newpwd = getcwd(buf, PATH_MAX);
	*env = fillenv("PWD", v.newpwd, find_env_var(*env, "PWD"));
	*env = fillenv("OLDPWD", v.pwd, find_env_var(*env, "OLDPWD"));
	free(v.pwd);
}

void		ft_cd_slash(char ***env)
{
	t_vatcdt v;

	v.pwd = ft_getenv(env, "PWD");
	*env = fillenv("PWD", "/", find_env_var(*env, "PWD"));
	*env = fillenv("OLDPWD", v.pwd, find_env_var(*env, "OLDPWD"));
	free(v.pwd);
	chdir("/");
}
