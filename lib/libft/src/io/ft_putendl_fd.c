/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:15:52 by ccouble           #+#    #+#             */
/*   Updated: 2024/01/02 04:44:08 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int	ft_putendl_fd(const char *s, int fd)
{
	int	putstr_output;
	int	putchar_output;

	putstr_output = ft_putstr_fd(s, fd);
	if (putstr_output < 0)
		return (-1);
	putchar_output = ft_putchar_fd(fd, '\n');
	if (putchar_output < 0)
		return (-1);
	return (putchar_output + putstr_output);
}
