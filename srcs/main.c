/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:49:11 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/21 12:04:25 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/21sh.h"

int main(int ac, char **av, char **envi)
{
    signal(2, ft_sig_kill);
    ft_21sh(envi);
    (void)ac;
    (void)av;
    return (0);
}