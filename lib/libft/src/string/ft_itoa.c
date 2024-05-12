/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/27 02:54:23 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*putnbr(long int nb, int digits);

char	*ft_itoa(int n)
{
	int			digits;
	long int	nb;

	if (n == 0)
		return (putnbr(0, 1));
	digits = 0;
	nb = n;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (putnbr(nb, digits));
}

static char	*putnbr(long int nb, int digits)
{
	char	*str;
	int		neg;

	neg = 0;
	if (nb < 0)
		neg = 1;
	str = malloc((digits + neg + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digits + neg] = '\0';
	if (neg)
		nb *= -1;
	else
		digits--;
	while (digits >= 0)
	{
		str[digits] = (nb % 10) + '0';
		nb /= 10;
		--digits;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
