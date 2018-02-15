/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:40:46 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:45:27 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_error(char *error, char *buf)
{
	ft_putcolormultistr_err(_R, "minishell: ", error, buf);
	ft_putchar_fd('\n', 2);
	return (0);
}
