/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:51:06 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/23 16:14:16 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/21sh.h"

void cd_change_env(char ***env, char *pwd, char *oldpwd, int m)
{
    if (pwd)
    {
        if(parseenv_env(env, pwd, "PWD", 1))
            *env = addenv_env(*env, "PWD", pwd);
    }
    if (oldpwd)
    {
        if(parseenv_env(env, oldpwd, "OLDPWD", 1))
            *env = addenv_env(*env, "OLDPWD", oldpwd);
    }
    if (m == 0)
        free(pwd);
    free(oldpwd);
}

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
    cd_change_env(env, v.oldpwd, v.pwd, 1);
	ft_putendl(v.oldpwd);
	chdir(v.oldpwd);
	free(v.oldpwd);
}

void		ft_cd_nothing(char ***env)
{
	t_vatcdt v;

	v.pwd = ft_getenv(env, "PWD");
	v.home = ft_getenv(env, "HOME");
    if (!v.home)
    {
        free(v.pwd);
        ft_error("cd: ","HOME PATH neot set");
        return;
    }
	cd_change_env(env, v.home, v.pwd, 0);
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
    cd_change_env(env, v.newpwd, v.pwd, 1);
}

void		ft_cd_slash(char ***env)
{
	t_vatcdt v;

	v.pwd = ft_getenv(env, "PWD");
    cd_change_env(env, "/", v.pwd, 1);
	chdir("/");
}
