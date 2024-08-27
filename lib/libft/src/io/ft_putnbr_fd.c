/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:17:49 by ccouble           #+#    #+#             */
/*   Updated: 2023/12/16 05:58:41 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <limits.h>

int	ft_putnbr_fd(int n, int fd)
{
	int	current;
	int	new;

	current = 0;
	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		new = ft_putchar_fd('-', fd);
		if (new < 0)
			return (-1);
		current += new;
		n *= -1;
	}
	if (n > 9)
	{
		new = ft_putnbr_fd(n / 10, fd);
		if (new < 0)
			return (-1);
		current += new;
	}
	new = ft_putchar_fd((n % 10) + '0', fd);
	if (new < 0)
		return (-1);
	return (current);
}
