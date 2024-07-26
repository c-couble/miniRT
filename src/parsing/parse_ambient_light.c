/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:50:59 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 04:11:53 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "object.h"
#include "color.h"
#include "object/parse_util.h"

int	parse_ambient_light(struct s_engine *engine, union u_object_data *data)
{
	char	*arg;

	(void) engine;
	arg = ft_strtok(NULL, " \t");
	if (parse_double(&data->ambient_light.ratio, arg, 0, 1) == -1)
		return (-1);
	if (parse_color(&data->ambient_light.color) == -1)
		return (-1);
	return (0);
}
