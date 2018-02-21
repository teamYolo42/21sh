/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:09:54 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/21 23:02:21 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

static int		echo_par(char *str, int i, char c)
{
	i++;
	while (str[i] && str[i] != c)
	{
        if (str[i] == 92)
            ft_92(str, i);
        else
		    ft_putchar(str[i]);
		i++;
	}
	return (i);
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
    t_echo v;
    char optecho[1];

    if (check_cot(str))
    {
        ft_error("echo: ", "Number of quote");
        return;
    }
    v.av = ft_specialsplit(str);
    if (!ft_checkcmd(v.av[0], "echo"))
    {
        freer(v.av);
        return ;
    }

    v.ac = (int) ft_scountwords(str, ' ');
    v.i = get_options_echo(optecho, v.av, v.ac);
    v.s = ft_joinsplitc(v.av, v.i, ' ');
    if (v.i == v.ac)
        ft_erroru("echo: ", "bas syntax", "echo [-n] [string...]");
    else
        ft_echo_norm(env, v.s);
    if (!OPT_ECHO_N)
        ft_putchar('\n');
    freer(v.av);
    free(v.s);
}

























































