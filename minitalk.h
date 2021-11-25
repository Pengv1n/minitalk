/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:23:25 by aregenia          #+#    #+#             */
/*   Updated: 2021/11/26 01:23:27 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "signal.h"
# include "unistd.h"
# include "stdlib.h"

void	ft_putstr_fd(char *msg, int fd);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif
