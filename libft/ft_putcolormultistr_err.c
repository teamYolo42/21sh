/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolormultistr_err.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:28:45 by null              #+#    #+#             */
/*   Updated: 2018/02/05 12:48:53 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putcolormultistr_err(char *color, char *a, char *b, char *c)
{
	ft_putstr_fd(color, 2);
	ft_putstr_fd(a, 2);
	ft_putstr_fd(b, 2);
	ft_putstr_fd(c, 2);
	ft_putstr_fd(_0, 2);
}
