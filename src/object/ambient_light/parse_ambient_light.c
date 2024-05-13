/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/13 21:54:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "object/rgb.h"
#include "object/parse_util.h"
#include <stdio.h>
#include <unistd.h>

int	parse_ambient_light(t_object_data *data)
{
	if (parse_double(&data->ambient_light.ratio, 0, 1) == -1)
		return (-1);
	if (parse_rgb(&data->ambient_light.color) == -1)
		return (-1);
	printf("A ratio=%lf r=%d g=%d b=%d\n", data->ambient_light.ratio, data->ambient_light.color.r, data->ambient_light.color.g, data->ambient_light.color.b);
	return (0);
}
