/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erroru.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:41:01 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:45:27 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_erroru(char *error, char *buf, char *usage)
{
	ft_putcolormultistr_err(_R, "minishell: ", error, buf);
	ft_putchar_fd('\n', 2);
	ft_putcolormultistr_err(_R, "usage: ", usage, "\n");
}
