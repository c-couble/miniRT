/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:46:07 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/29 05:47:54 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	parse_int(int *data, const char *nptr, double min, double max)
{
	if (ft_atoi_ptr(data, nptr) == -1)
		return (-1);
	if (*data > max || *data < min)
		return (-1);
	return (0);
}
