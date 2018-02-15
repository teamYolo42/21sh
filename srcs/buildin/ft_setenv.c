/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:40:29 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:48:40 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

static	char	**addenv(char *name, char *value)
{
	char	*str;

	str = ft_strdup(name);
	str = ft_strjoinfrees1(str, "=");
	str = ft_strjoinfrees1(str, value);
	g_env = ft_reallocd(g_env, 1, str);
	free(str);
	return (g_env);
}

char			**fillenv(char *name, char *value, int j)
{
	char	*str;

	str = ft_strdup(name);
	str = ft_strjoinfrees1(str, "=");
	str = ft_strjoinfrees1(str, value);
	ft_bzero(g_env[j], ft_strlen(g_env[j]));
	g_env[j] = ft_strjoinfree(g_env[j], str);
	return (g_env);
}

int				parseenv(char *value, char *name, int overwrite)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = g_env;
	while (tmp[j])
	{
		if (ft_strcmpcuts1(tmp[j], name, '=') == 0)
		{
			if (overwrite != 0)
				g_env = fillenv(name, value, j);
			return (0);
		}
		j++;
	}
	return (1);
}

static	int		checksyntax(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != ' ' && str[i] != '=' && str[i])
		i++;
	if (str[i] == '=')
	{
		i++;
		if (!str[i])
			return (1);
		while (str[i] != ' ' && str[i])
			i++;
		if (!str[i])
			return (-1);
		i++;
		if ((!str[i] || str[i] == '0' || str[i] == '1') && !str[i + 1])
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

void			ft_setenv(char *str, int m)
{
	int		in[2];
	char	*name;
	char	*value;

	if (m == 0)
		ft_strcut(str, 7);
	if ((in[0] = checksyntax(str)) == 1)
	{
		ft_erroru("setenv: ",
			"bad syntax", "setenv [name]=[value] [overwrite : 0/1]");
		return ;
	}
	if (in[0] == -1)
		in[1] = 0;
	else
		in[1] = ft_atoi(ft_strchr(str, ' '));
	name = ft_strgetchartc(str, '=');
	value = ft_cut(str, '=');
	if (in[0] != -1)
		value = ft_strgetchartc(str, ' ');
	if (parseenv(value, name, in[1]))
		g_env = addenv(name, value);
	free(name);
	if (in[0] != -1)
		free(value);
}
