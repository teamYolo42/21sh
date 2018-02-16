/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:09:22 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/15 18:33:16 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FNC_H
# define FNC_H
# include "stuct.h"

void    ft_puttab(char **tab);
void	ft_21sh(char **env);

void	ft_env(char ***env, char *str);

int		ft_error(char *error, char *buf);
void	ft_erroru(char *error, char *buf, char *usage);

void	ft_echo(char ***env, char *str);
void	ft_cutspace(char *str);
int		ft_ispace(char c);
void	ft_setenv(char *str, int m);
void	ft_unsetenv(char *str, int m);
int		find_env_var(char **env, char *var);
void	ft_cd(char ***env, char *str);
int		parseenv(char *value, char *key, int ov);
int		ft_exec(char ***env, char ***cenv, char *str);
char	**fillenv(char *key, char *value, int j);
char	*ft_getenv(char ***env, char *var);
char	*ft_getenv_2(char **env, char *str);
void	ft_exit(char *str);
void	ft_delspace(char *str);

void	freer(char **str);
int		testcd(char **path, int m, char *save);

void	ft_cd_tiret(char ***env);
void	ft_cd_nothing(char ***env);
void	ft_cd_norm(char ***env, char **str, int m);
void	ft_cd_slash(char ***env);
int		ft_env_len(char *str, int i);

void	ft_sig_kill(int sig);
void	ft_affprompt(void);
void	ft_starting(void);

int		ft_setenv_env(char ***env, char *str);
void	go(char ***env, char ***cenv,  char *buf, int m);

int		get_options_env(char *optenv, char **argv, int argc);
int		ft_tablen(char **tab);
int		checksyntax_env(const char *str);

#endif
