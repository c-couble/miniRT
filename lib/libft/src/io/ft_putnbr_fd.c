/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:17:49 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:28:12 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_io.h"

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
