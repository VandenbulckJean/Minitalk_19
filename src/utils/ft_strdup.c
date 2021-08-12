/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:32:22 by jvanden-          #+#    #+#             */
/*   Updated: 2021/08/12 12:32:56 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(sizeof(*dup) * (ft_strlen(s1) + 1));
	if (!dup)
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
