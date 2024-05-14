/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:33:58 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 02:57:44 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <errno.h>
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	n;
	int	sign;

	while (ft_isspace(*nptr))
		++nptr;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (n > (INT_MAX / 10) - (*nptr - '0'))
		{
			errno = EOVERFLOW;
			return (0);
		}
		n = n * 10 + (*nptr - '0');
		++nptr;
	}
	if (*nptr)
		errno = EINVAL;
	return (n * sign);
}
