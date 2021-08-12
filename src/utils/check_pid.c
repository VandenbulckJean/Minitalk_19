/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:14:26 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/12 17:22:25 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	check_pid(char *str)
{
	int	pid;

	if (!(ft_is_only_number(str)) || ft_strlen(str) > 5)
		return (-1);
	pid = ft_atoi(str);
	if (pid < 0 || pid > 32768)
		return (-1);
	return (pid);
}
