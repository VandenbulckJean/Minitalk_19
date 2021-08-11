/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:40:39 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 16:55:23 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_message
{
	char	*full;
	char	char_in_progress;
	char	char_received;
	char	current_char_bit_received;
}	t_message;

//UTILS
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
int		ft_atoi(const char *str);

#endif