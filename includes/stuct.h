/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:23:16 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/20 18:23:01 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUCT_H
# define STUCT_H

typedef struct	s_varcdt
{
	char	*pwd;
	char	*oldpwd;
	char	*home;
	char	*newpwd;
}				t_vatcdt;

typedef struct	s_varcdnorm
{
	char	**split;
	int		m;
	char	buf[2048];
}				t_vcdn;

typedef struct	s_execute
{
	char	*e_path;
	char	*path;
	char	*builtin;
	char	**argv;
	int		i;
}				t_exe;

typedef	struct	s_setenv
{
    int         i;
    char        **av;
    char        optsetenv[1];
    int         ac;
}				t_setenv;


#endif
