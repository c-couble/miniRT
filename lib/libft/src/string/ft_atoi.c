/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:33:58 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/27 02:55:03 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include <stddef.h>
#include <limits.h>

static long int	ft_atol(const char *nptr);
static long int	next(long int nb, char next);

int	ft_atoi(const char *nptr)
{
	return (ft_atol(nptr));
}

static long int	ft_atol(const char *nptr)
{
	size_t		i;
	long int	nb;

	nb = 0;
	i = 0;
	while (nptr[0] == ' ' || (nptr[0] >= '\t' && nptr[0] <= '\r'))
		nptr++;
	if (nptr[i] == '+' || nptr[i] == '-')
		++i;
	while (ft_isdigit(nptr[i]))
	{
		nb = next(nb, nptr[i]);
		if (nb == -1 && nptr[0] == '-')
			return (LONG_MIN);
		else if (nb == -1)
			return (LONG_MAX);
		++i;
	}
	if (nptr[0] == '-')
		return (nb * -1);
	return (nb);
}

static long int	next(long int nb, char next)
{
	if (nb > LONG_MAX / 10)
		return (-1);
	nb *= 10;
	if (nb > LONG_MAX - (next - '0'))
		return (-1);
	nb += (next - '0');
	return (nb);
}
