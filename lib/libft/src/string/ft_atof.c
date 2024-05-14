/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:18:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 02:52:30 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "float.h"
#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <errno.h>

static double	get_fractional_part(const char *nptr);

double	ft_atof(const char *nptr)
{
	int		sign;
	double	n;

	n = 0;
	while (ft_isspace(*nptr))
		++nptr;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if ((DBL_MAX / 10) - (*nptr - '0') < n)
		{
			errno = EOVERFLOW;
			return (0);
		}
		n = n * 10 + (*nptr - '0');
		++nptr;
	}
	return ((n + get_fractional_part(nptr)) * sign);
}

static double	get_fractional_part(const char *nptr)
{
	double	n;
	double	fraction;

	if (*nptr != '.')
	{
		if (*nptr != '\0')
			errno = EINVAL;
		return (0);
	}
	++nptr;
	n = 0;
	fraction = 0.1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n += fraction * (*nptr - '0');
		fraction /= 10;
		++nptr;
	}
	if (*nptr != '\0')
		errno = EINVAL;
	return (n);
}
