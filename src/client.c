/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:28:06 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 16:31:27 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_string(char *str, int pid)
{
	int	bitshift;

	while (*str)
	{
		bitshift = 7;
		while (bitshift >= 0)
		{
			if ((*str >> bitshift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(3);
			bitshift--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "ERROR: arguments invalid.\n", 26);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_string(argv[2], pid);
	return (0);
}
