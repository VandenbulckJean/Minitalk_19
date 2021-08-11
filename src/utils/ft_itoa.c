/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:54:21 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/11 15:10:06 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static int	nb_char(int n)
{
	int				res;
	unsigned int	u;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res++;
		u = -n;
	}
	else
		u = n;
	while (u)
	{
		res++;
		u = u / 10;
	}
	return (res);
}

static void	ten_to_str(unsigned int n, char *res, int *i)
{
	if (n / 10 == 0)
		res[++*i] = '0' + n % 10;
	else
	{
		ten_to_str(n / 10, res, i);
		res[++*i] = '0' + n % 10;
	}
}

char	*ft_itoa(int n)
{
	char			*res;
	int				i;
	unsigned int	u;

	res = (char *)malloc(sizeof(char) * (nb_char(n) + 1));
	if (!res)
		return (NULL);
	i = -1;
	if (n < 0)
	{
		u = (unsigned int) -n;
		res[++i] = '-';
	}
	else
		u = (unsigned int)n;
	ten_to_str(u, res, &i);
	res[++i] = '\0';
	return (res);
}
