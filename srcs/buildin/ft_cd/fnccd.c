/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdfnc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:23:58 by asandolo          #+#    #+#             */
/*   Updated: 2018/03/01 15:26:57 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

static void	test(char *str)
{
	struct stat stat;

	if (lstat(str, &stat) >= 0)
	{
		if (!(stat.st_mode & S_IXUSR))
			ft_error("cd: ", "permission denied");
	}
	else
		ft_error("cd: ", "no such file or directory");
}

static	int	go_home(int i)
{
	char *home;

	home = ft_getenv(&g_env, "HOME");
	chdir(home);
	if (home)
		free(home);
	i++;
	return (i);
}

int			testcd(char **path, int m, char *save)
{
	int i;
	DIR *d;

	i = 0;
	if (m)
		chdir("/");
	if (ft_strcmp(path[i], "~") == 0)
		i = go_home(i);
	while (path[i])
	{
		if ((d = opendir(path[i])))
		{
			chdir(path[i]);
			closedir(d);
		}
		else
		{
			test(path[i]);
			chdir(save);
			return (0);
		}
		i++;
	}
	chdir(save);
	return (1);
}

int	testcd2(char *str)
{
	DIR *d;

	if ((d = opendir((str))))
	{
		closedir(d);
		return (1);
	}
	else
	{
		test(str);
		return (0);
	}
}
