/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_launcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:40:08 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 17:01:40 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	print_number(int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	ft_putstr(str);
	free(str);
}

static void	receive_char(int signo, t_message *message)
{
	if (signo == SIGUSR1)
		message->char_in_progress ^= 1 << message->current_char_bit_received;
}

static void	receive_message(int signo, t_message *message)
{
	if (message->current_char_bit_received < 8)
		receive_char(signo, message);
}

static void	handle_sigusr1(int signo)
{
	(void)signo;
	ft_putchar('1');
}

static void	handle_sigusr2(int signo)
{
	(void)signo;
	ft_putchar('0');
}

int	main(void)
{
	pid_t		pid;
	t_message	message;

	pid = getpid();
	message.char_in_progress = 0;
	message.char_received = 0;
	message.current_char_bit_received = 0;
	write(1, "PID: ", 5);
	print_number(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handle_sigusr1);
		signal(SIGUSR2, handle_sigusr2);
		pause();
	}
		
}
