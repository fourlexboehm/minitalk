/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org.au>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:09:12 by aboehm            #+#    #+#             */
/*   Updated: 2021/12/08 15:16:36 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_char(pid_t	sPid, char c)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (c >> j & 1)
			kill(sPid, SIGUSR2);
		else
			kill(sPid, SIGUSR1);
		usleep(100);
		j--;
	}
}

static void	send_str(pid_t	sPid, char *Str)
{
	while (*Str)
		send_char(sPid, *Str++);
}

void	usage(void)
{
	ft_printf("./client [server-pid] [message]\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*msg;

	if (argc != 3)
		usage();
	server_pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_str(server_pid, msg);
}
