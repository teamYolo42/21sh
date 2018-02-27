/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnccd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:37:09 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/27 15:39:57 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"


static char **ft_removedots(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if(ft_strcmp(split[i], ".") == 0)
		{
			split = ft_removefromtab(split, i);
			i = 0;
		}
		if(ft_strcmp(split[i], "..") == 0)
		{
			split = ft_removefromtab2(split, i);
			i = 0;
		}
		i++;
	}
	return (split);
}

char	*cd_parse_path(char ***env, char *npath)
{
	char *path;
	char **split;
	char **nsplit;
	char *nnpath;
	char *s;

	path = ft_getenv(env, "PWD");
	if (npath[0] == '/')
		nnpath = path;
	else
	{
		nnpath = ft_strjoincfree(path, '/');
		nnpath = ft_strjoinfrees1(nnpath, npath);
	}
	split = ft_strsplit(nnpath, '/');
	free(nnpath);
	nsplit = ft_removedots(split);
	freer(split);
	s = ft_joinsplitc(nsplit, 0, '/');
	freer(nsplit);
	s = ft_strjoinfrees2("/", s);
	ft_putendl(s);
	return (s);
}