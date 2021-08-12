/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:43:18 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/12 13:44:06 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	ft_print_int(int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	ft_putstr(str);
	free(str);
}
