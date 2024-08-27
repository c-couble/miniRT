/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:17:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/04/15 06:44:48 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "vector.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static int	flag_handler(va_list *lst, t_vector *buffer, char *format);
static int	parse_string(va_list *lst, t_vector *buffer, char *format);

int	ft_dprintf(int fd, char *format, ...)
{
	va_list		lst;
	t_vector	buffer;
	int			ret;

	if (format == NULL)
		return (-1);
	init_vector(&buffer, sizeof(char));
	va_start(lst, format);
	if (parse_string(&lst, &buffer, format) == -1)
	{
		clear_vector(&buffer);
		va_end(lst);
		return (-1);
	}
	ret = buffer.size;
	va_end(lst);
	if (write(fd, at_vector(&buffer, 0), buffer.size) != ret)
		ret = -1;
	clear_vector(&buffer);
	return (ret);
}

static int	parse_string(va_list *lst, t_vector *buffer, char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (flag_handler(lst, buffer, format) == -1)
				return (-1);
			++format;
		}
		if (add_vector(buffer, format, 1) == -1)
			return (-1);
		++format;
	}
	return (0);
}

static int	flag_handler(va_list *lst, t_vector *buffer, char *format)
{
	char	*curr;

	if (*format == 'd')
	{
		curr = ft_itoa(va_arg(*lst, int));
		if (curr == NULL)
			return (-1);
		if (add_vector(buffer, curr, ft_strlen(curr)) == -1)
		{
			free(curr);
			return (-1);
		}
		free(curr);
	}
	else if (*format == 's')
	{
		curr = va_arg(*lst, char *);
		if (curr == NULL)
			return (-1);
		if (add_vector(buffer, curr, ft_strlen(curr)) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
