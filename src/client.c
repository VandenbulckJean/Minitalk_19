/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:28:06 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/12 17:06:02 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_transfer_data	g_data;

void	error_manager(void)
{
	if (g_data.text)
		free(g_data.text);
	write(2, "ERROR: unexpected from client.\n", 31);
	exit(EXIT_FAILURE);
}

static int	send_end_signal(void)
{
	static int	i = 0;

	if (i++ < 8)
	{
		if (kill(g_data.correspondent_pid, SIGUSR1))
			error_manager();
		return (0);
	}
	return (1);
}

static int	send_text_bit_by_bit(void)
{
	if (*g_data.current_sending_char)
	{
		if ((*g_data.current_sending_char >> g_data.current_bit) & 1)
		{
			if (kill(g_data.correspondent_pid, SIGUSR2))
				error_manager();
		}
		else
		{
			if (kill(g_data.correspondent_pid, SIGUSR1))
				error_manager();
		}
		if (g_data.current_bit == 7)
		{
			g_data.current_sending_char++;
			g_data.current_bit = 0;
		}
		else
			g_data.current_bit++;
		return (0);
	}
	if (!send_end_signal())
		return (0);
	free(g_data.text);
	return (1);
}

static void	handle_signal(int signo)
{
	int	is_over;

	is_over = 0;
	if (signo == SIGUSR1)
		is_over = send_text_bit_by_bit();
	else if (signo == SIGUSR2)
	{
		if (g_data.text)
			free(g_data.text);
		write(2, "ERROR: unexpected from server.\n", 31);
		exit(EXIT_FAILURE);
	}
	if (is_over)
	{
		write(1, "Message sent succesfully.\n", 26);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_is_only_number(argv[1]))
	{
		write(2, "ERROR: arguments invalid.\n", 26);
		exit(EXIT_FAILURE);
	}
	g_data.text = ft_strdup(argv[2]);
	if (!g_data.text)
		error_manager();
	g_data.current_sending_char = g_data.text;
	g_data.correspondent_pid = ft_atoi(argv[1]);
	g_data.current_bit = 0;
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	send_text_bit_by_bit();
	while (1)
		pause();
	return (0);
}
