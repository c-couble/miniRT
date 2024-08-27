/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:49:28 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 16:36:49 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "float.h"

static int	get_fractional_part(double *nbptr, const char *nptr);

int	ft_atof_ptr(double *nbptr, const char *nptr)
{
	int		sign;

	*nbptr = 0;
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
		if (*nbptr > (DBL_MAX / 10) - (*nptr - '0'))
			return (-1);
		*nbptr = *nbptr * 10 + (*nptr - '0');
		++nptr;
	}
	if (get_fractional_part(nbptr, nptr) == -1)
		return (-1);
	*nbptr *= sign;
	return (0);
}

static int	get_fractional_part(double *nbptr, const char *nptr)
{
	double	fraction;

	if (*nptr != '.')
	{
		if (*nptr != '\0')
			return (-1);
		return (0);
	}
	++nptr;
	fraction = 0.1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		*nbptr += fraction * (*nptr - '0');
		fraction /= 10;
		++nptr;
	}
	if (*nptr != '\0')
		return (-1);
	return (0);
}
