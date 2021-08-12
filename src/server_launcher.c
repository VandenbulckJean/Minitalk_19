/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_launcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:40:08 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/12 17:06:03 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_transfer_data	g_data;

static void	print_text(void)
{
	ft_putstr(g_data.text);
	ft_putchar('\n');
	ft_putstr("End of transmission.\n");
	free(g_data.text);
	g_data.text = NULL;
}

static void	error_manager(void)
{
	if (g_data.text)
		free(g_data.text);
	write(2, "ERROR: unexpected from server.\n", 31);
	kill(g_data.correspondent_pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

static void	handle_signal(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid)
		g_data.correspondent_pid = info->si_pid;
	if (signo == SIGUSR2)
		g_data.c |= 1 << g_data.current_bit;
	else
		g_data.c ^= 1 << g_data.current_bit;
	if (++g_data.current_bit == 8)
	{
		if (g_data.c)
			g_data.text = ft_straddc(g_data.text, g_data.c);
		else
			print_text();
		g_data.current_bit = 0;
		g_data.c = 0xFF;
	}
	if (kill(g_data.correspondent_pid, SIGUSR1))
		error_manager();
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			forbidden_signals;

	write(1, "PID: ", 5);
	ft_print_int(getpid());
	write(1, "\n", 1);
	g_data.c = 0xFF;
	g_data.current_bit = 0;
	g_data.correspondent_pid = 0;
	sigemptyset(&forbidden_signals);
	sigaddset(&forbidden_signals, SIGINT);
	sigaddset(&forbidden_signals, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = forbidden_signals;
	sa_signal.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		pause();
}
