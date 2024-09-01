/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:38:47 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_string.h"
#include "object.h"
#include "object/parse_util.h"

int	parse_ambient_light(t_object_data *data)
{
	char	*arg;

	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->ambient_light.ratio, arg, 0, 1) == -1)
		return (-1);
	if (parse_color(&data->ambient_light.color) == -1)
		return (-1);
	return (0);
}
