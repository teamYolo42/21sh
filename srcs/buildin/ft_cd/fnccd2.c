/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnccd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:37:09 by asandolo          #+#    #+#             */
/*   Updated: 2018/03/01 18:53:29 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"


static char **ft_removedots(char **split)
{
	int i;

	i = 0;
	while (split && split[i])
	{
		if(split[i] && ft_strcmp(split[i], ".") == 0)
		{
			split = ft_removefromtab(split, i);
			i = 0;
		}
		if(split[i] && ft_strcmp(split[i], "..") == 0)
		{
			split = ft_removefromtab2(split, i);
			i = 0;
		}
		i++;
	}
	return (split);
}

static int testcd3(char **s)
{
	int len;
	int i;
	int c;

	i = 0;
	c = 0;
	len = ft_tablen(s);
	while (s[i])
	{
		if (ft_strcmp(s[i], ".") == 0)
			c++;
		if (ft_strcmp(s[i], "..") == 0)
			c += 2;
		i++;
	}
	if ((len - c) < 0)
		return (0);
	else
		return (1);
}

char	*cd_parse_path(char ***env, char *npath)
{
	char *path;
	char **split;
	char **nsplit;
	char *nnpath;
	char *s;
	char *ret;

	path = ft_getenv(env, "PWD");
	if (npath[0] == '/')
	{
		nnpath = ft_strdup(npath);
		free(path);
	}
	else
	{
		nnpath = ft_strjoincfree(path, '/');
		nnpath = ft_strjoinfrees1(nnpath, npath);
	}
	split = ft_strsplit(nnpath, '/');
	free(nnpath);
	if (testcd3(split))
	{
		nsplit = ft_removedots(split);
		s = ft_joinsplitc(nsplit, 0, '/');
		freer(nsplit);
		ret = ft_strjoinfrees2("/", s);
		return (ret);
	}
	else
	{
		freer(split);
		return(NULL);
	}
}