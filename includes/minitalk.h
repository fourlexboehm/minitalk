/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:51:21 by aboehm            #+#    #+#             */
/*   Updated: 2022/01/10 15:51:23 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_data
{
	int		i;
	char	x;
	int		client_pid;
}	t_data;

void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	usage(void);
void	reset_data(void);
//void	handler(int sig, siginfo_t *info, void *ucontext);
void	handler(int sig);

int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
#endif
