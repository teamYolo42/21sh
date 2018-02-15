/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcartau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:35:08 by pcartau           #+#    #+#             */
/*   Updated: 2018/02/15 15:58:13 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKEFILE_H
# define MAKEFILE_H

# include "../libft/includes/color.h"
# include "../includes/21sh.h"
# define BUFF_SIZE 32

int     gnl(const int fd, char **line);
void    ft_putmultistr(char *s1, char *s2, char *s3);

#endif
