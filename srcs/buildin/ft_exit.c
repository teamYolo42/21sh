/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:06:07 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:45:27 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(char *str)
{
	int	i;

	i = 0;
	ft_strcut(str, 4);
	if (!ft_ispace(str[0]))
	{
		if (ft_strcmp(str, "") == 0)
			exit(0);
		else
		{
			ft_error("Error: ", "command not found");
			return ;
		}
	}
	exit(ft_atoi(str));
}
