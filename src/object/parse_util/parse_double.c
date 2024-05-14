/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:30:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 02:47:10 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <errno.h>

int	parse_double(double *data, double min, double max)
{
	char	*arg;

	arg = ft_strtok(NULL, " \t");
	if (arg == NULL)
		return (-1);
	*data = ft_atof(arg);
	if (*data > max || *data < min)
		return (-1);
	if (errno)
		return (-1);
	return (0);
}
