/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:40:39 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/12 17:19:04 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_transfer_data
{
	int		correspondent_pid;
	char	*text;
	char	*current_sending_char;
	char	current_bit;
	char	c;
}	t_transfer_data;

//UTILS
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
int		ft_atoi(const char *str);
int		ft_is_only_number(char *str);
char	*ft_strdup(const char *s1);
void	ft_print_int(int nbr);
char	*ft_straddc(char *str, char c);
int		check_pid(char *str);

#endif