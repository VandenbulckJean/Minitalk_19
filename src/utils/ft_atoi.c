/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:32:48 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 15:33:18 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signe;

	signe = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		signe = 44 - str[i];
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + signe * (str[i] - '0');
		i++;
	}
	return (res);
}
