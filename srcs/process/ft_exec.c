/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:57:13 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/16 14:05:49 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

void	clean(t_exe exec)
{
	int		i;

	i = 0;
	while (exec.argv[i])
	{
		if (exec.argv[i])
			free(exec.argv[i]);
		i++;
	}
	if (exec.argv)
		free(exec.argv);
	if (exec.e_path)
	{
		free(exec.e_path);
		free(exec.path);
	}
	free(exec.builtin);
}

void	freess(char *s)
{
	if (s)
		free(s);
	else
		ft_error("Error: ", "command not found");
}

void	execute(char ***cenv, t_exe exec)
{
	pid_t	pid;

	pid = fork();
	g_pid = pid;
	if (pid != 0)
		return ;
	if (execve(exec.builtin, exec.argv, *cenv) == -1 && !exec.e_path)
		ft_error("Error: ", "command not found");
	if (exec.e_path)
	{
		while (exec.path && execve(exec.path, exec.argv, *cenv) == -1)
		{
			free(exec.path);
			exec.path = ft_strgetstatic(exec.e_path, &exec.i, ':');
			if (exec.path)
			{
				exec.path = ft_strjoinfrees1(exec.path, "/");
				exec.path = ft_strjoinfrees1(exec.path, exec.builtin);
			}
		}
		freess(exec.path);
	}
	exit(1);
}

int		ft_exec(char ***env, char ***cenv, char *str)
{
	t_exe	exec;

	exec.i = 0;
	exec.e_path = ft_getenv_2(*env, "PATH");
	if ((exec.e_path))
		exec.path = ft_strgetstatic(exec.e_path, &exec.i, ':');
	exec.builtin = ft_strdup(str);
	if ((exec.builtin = ft_strgetchartc_nm(exec.builtin, ' ')) == NULL)
		exec.builtin = ft_strdup(str);
	if (exec.e_path)
	{
		exec.path = ft_strjoinfrees1(exec.path, "/");
		exec.path = ft_strjoinfrees1(exec.path, exec.builtin);
	}
	ft_replacechar(str, '\t', ' ');
	exec.argv = ft_strsplit(str, ' ');
	execute(cenv, exec);
	clean(exec);
	wait(NULL);
	return (0);
}
