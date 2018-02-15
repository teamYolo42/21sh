/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:03:02 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/09 10:52:29 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

static	void	*removevar(char **ptr, char *str)
{
	char	**newptr;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_tablen(ptr);
	if (!(newptr = (char **)malloc(sizeof(char *) * (ft_tablen(ptr)))))
		return (NULL);
	while (i < len)
	{
		if (ft_strcmpcuts1(ptr[i], str, '=') != 0)
			newptr[j++] = ptr[i];
		else
			free(ptr[i]);
		i++;
	}
	newptr[j] = 0;
	free(ptr);
	return (newptr);
}

void			ft_unsetenv(char *str, int m)
{
	char *tmp;

	if (m == 0)
	{
		ft_strcut(str, 9);
		ft_delspace(str);
	}
	tmp = ft_getenv(&g_env, str);
	if (tmp)
		g_env = removevar(g_env, str);
	else
		ft_error("unsetenv: ", "var not found");
	if (tmp)
		free(tmp);
}
