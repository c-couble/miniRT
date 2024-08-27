/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:30:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 08:17:39 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

int	parse_double(double *data, const char *nptr, double min, double max)
{
	if (nptr == NULL)
		return (-1);
	if (ft_atof_ptr(data, nptr) == -1)
		return (-1);
	if (*data > max || *data < min)
		return (-1);
	return (0);
}
