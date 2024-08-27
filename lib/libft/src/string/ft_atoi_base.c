/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:13:41 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/27 01:50:28 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include <limits.h>

size_t	ft_get_base_number(char c, char *base);

int	ft_atoi_base(char *str, char *base)
{
	const int		base_len = ft_strlen(base);
	unsigned int	number;

	number = 0;
	while (ft_isspace(*str))
		++str;
	while (*str && ft_strchr(base, *str))
	{
		if (UINT_MAX / base_len < number)
			return (-1);
		number *= base_len;
		if (UINT_MAX - ft_get_base_number(*str, base) < number)
			return (-1);
		number += ft_get_base_number(*str, base);
		++str;
	}
	return (number);
}

size_t	ft_get_base_number(char c, char *base)
{
	size_t	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
