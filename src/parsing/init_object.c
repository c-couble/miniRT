/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:22:30 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/12 16:02:05 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bvh.h"
#include "ft_string.h"
#include "object.h"
#include "object/optional_data.h"

static t_object_type	get_object_type(char *type);
static int				parse_object(t_engine *engine, t_object *object);

int	init_object(t_engine *engine, t_object *object, char *line)
{
	char	*word;

	word = ft_strtok(line, " ");
	if (word == NULL)
	{
		object->type = COMMENT;
		return (0);
	}
	object->type = get_object_type(word);
	if (object->type == UNKNOWN_OBJ)
		return (-1);
	if (object->type == COMMENT)
		return (0);
	if (parse_object(engine, object) == -1)
		return (-1);
	if (object->type != LIGHT
		&& object->type != AMBIENT_LIGHT && object->type != CAMERA)
	{
		if (object->type == SPHERE)
			get_sphere_aabb(&object->data.sphere, object);
		if (object->type == PARABOLOID)
			get_paraboloid_aabb(&object->data.paraboloid, object);
		if (object->type == CYLINDER)
			get_cylinder_aabb(&object->data.cylinder, object);
		if (parse_optional_data(engine, object) == -1)
			return (-1);
	}
	return (0);
}

static t_object_type	get_object_type(char *type)
{
	static char	*values[] = {
	[AMBIENT_LIGHT] = "A",
	[CAMERA] = "C",
	[LIGHT] = "L",
	[SPHERE] = "sp",
	[PLANE] = "pl",
	[CYLINDER] = "cy",
	[PARABOLOID] = "pa",
	[TRIANGLE] = "tr",
	[MESH] = "mesh",
	};
	size_t		i;

	if (type[0] == '#')
		return (COMMENT);
	i = 0;
	while (i < UNKNOWN_OBJ)
	{
		if (ft_strcmp(values[i], type) == 0)
			return (i);
		++i;
	}
	return (UNKNOWN_OBJ);
}

static int	parse_object(t_engine *engine, t_object *object)
{
	static int	(*values[])(t_engine *engine, t_object_data *data) = {
	[AMBIENT_LIGHT] = parse_ambient_light,
	[CAMERA] = parse_camera,
	[LIGHT] = parse_light,
	[SPHERE] = parse_sphere,
	[PLANE] = parse_plane,
	[CYLINDER] = parse_cylinder,
	[PARABOLOID] = parse_paraboloid,
	[TRIANGLE] = parse_triangle,
	[MESH] = parse_mesh,
	};

	(void)engine;
	return (values[object->type](engine, &object->data));
}
