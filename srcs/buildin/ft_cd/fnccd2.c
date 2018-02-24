/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnccd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:37:09 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/24 18:41:21 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"


char **ft_jspencoe(char **split, int j)
{
	int i;
	char **nsplit;

	i = 0;
	ft_putnbr(j);
	ft_putendl("");
	while (split[i])
	{
		if(ft_strcmp(split[i], "..") == 0)
		{
			nsplit = ft_removefromtab2(split, i);
			ft_puttabd(nsplit);
			ft_putendl("");
			ft_jspencoe(nsplit, j + 1);
		}
		i++;
	}
	return (split);
}

void	cd_parse_path(char ***env, char *npath)
{
	char *path;
	char **split;
	char **nsplit;
	char *nnpath;
	int	i;

	i = 0;
	path = ft_getenv(env, "PWD");
	if (npath[0] == '/')
		nnpath = path;
	else
	{
		nnpath = ft_strjoincfree(path, '/');
		nnpath = ft_strjoinfrees1(nnpath, npath);
	}
	split = ft_strsplit(nnpath, '/');
	nsplit = ft_jspencoe(split, 0);
	ft_putendl("FINAL");
	ft_puttabd(nsplit);
}