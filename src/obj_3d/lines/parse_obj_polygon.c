/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_polygon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:22:58 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/22 16:23:33 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "ft_string.h"
#include "obj_3d.h"

static int	parse_polygon_point(t_polygon_point *point, char *arg);

int	parse_obj_polygon(t_engine *engine, t_obj_3d *obj, char *line)
{
	t_polygon	poly;
	char		*save;

	(void) engine;
	poly.material = obj->current_material;
	if (parse_polygon_point(&poly.points[0], ft_strtok_r(line, " \t", &save)) == -1)
		return (-1);
	if (parse_polygon_point(&poly.points[1], ft_strtok_r(NULL, " \t", &save)) == -1)
		return (-1);
	if (parse_polygon_point(&poly.points[2], ft_strtok_r(NULL, " \t", &save)) == -1)
		return (-1);
	if (add_vector(&obj->faces, &poly, 1) == -1)
		return (-1);
	return (0);
}

static int	parse_polygon_point(t_polygon_point *point, char *arg)
{
	if (arg == NULL)
		return (-1);
	point->vertice_id = ft_atoi(arg);
	point->texture_id = -1;
	point->normal_id = -1;
	arg = ft_strchr(arg, '/');
	if (arg == NULL)
		return (0);
	++arg;
	if (*arg != '/')
		point->texture_id = ft_atoi(arg);
	arg = ft_strchr(arg, '/');
	if (arg == NULL)
		return (0);
	++arg;
	point->normal_id = ft_atoi(arg);
	return (0);
}
