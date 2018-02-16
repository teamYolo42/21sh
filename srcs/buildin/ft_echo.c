/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:09:54 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/16 14:42:20 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

static int		echo_par(char *str, int i, char c)
{
	i++;
	while (str[i] && str[i] != c)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

static int		check_cot(const char *str)
{
	int i;
	int ck;

	i = 0;
	ck = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == 39)
			ck++;
		i++;
	}
	return (((ck % 2) == 0) ? 0 : 1);
}

static	int		ft_echo_env(char ***env, char *str, int i)
{
	char	*tmp;
	char	*tmp2;
	int		end;

	tmp2 = "";
    tmp = NULL;
	i++;
	end = ft_env_len(str, i);
	while (str[i] && !ft_ispace(str[i]))
	{
		tmp2 = ft_strjoinc(tmp2, str[i]);
		if (i < end - 1)
			free(tmp2);
		i++;
	}
    if (*env)
	    tmp = ft_getenv(env, tmp2);
	if (tmp)
	{
		ft_putstr(tmp);
		free(tmp);
		ft_putchar(' ');
	}
	free(tmp2);
	return (i);
}

static void		ft_echo_norm(char ***env, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != '"' && str[i + 1] != 39)
			i = ft_echo_env(env, str, i);
		else if (str[i] == '$' && (str[i + 1] == 39))
			i++;
		else if (str[i] == '"' || str[i] == 39)
			i = echo_par(str, i, str[i]);
		else
		{
			while (ft_ispace(str[i]) && ft_ispace(str[i + 1]))
				i++;
			if (ft_ispace(str[i]) && str[i + 1] == '\0')
				break ;
			if (ft_ispace(str[i]) && ft_isalnum(str[i + 1]))
				ft_putstr("");
			ft_putchar(str[i]);
		}
		i++;
	}
}

void			ft_echo(char ***env, char *str)
{
	ft_strcut(str, 4);
	if (!ft_ispace(str[0]))
	{
		ft_error("Error: ", "command not found");
		return ;
	}
	ft_cutspace(str);
	if (check_cot(str))
	{
		ft_error("echo: ", "Number of quote");
		return ;
	}
	ft_echo_norm(env, str);
	ft_putchar('\n');
}
