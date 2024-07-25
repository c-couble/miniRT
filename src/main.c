/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:26:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/24 22:27:06 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "obj_3d.h"
#include "object.h"
#include "vec3.h"
#include "vec4.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_engine	engine;

	if (write(STDOUT_FILENO, "miniRT\n", 7) != 7)
		return (1);
	t_obj_3d	obj;
	if (parse_obj_file(&obj, "./bear.obj") == -1)
	{
		write(2, "Error obj\n", 10);
		return (2);
	}
	size_t i = 0;
	while (i < obj.vertices.size)
	{
		t_vec4 *vec = at_vector(&obj.vertices, i);
		printf("vertice %lf %lf %lf %lf\n", vec->x, vec->y, vec->z, vec->w);
		++i;
	}
	i = 0;
	while (i < obj.texture_coordinates.size)
	{
		t_vec3 *vec = at_vector(&obj.texture_coordinates, i);
		printf("texture %lf %lf %lf\n", vec->x, vec->y, vec->z);
		++i;
	}
	i = 0;
	while (i < obj.vertex_normals.size)
	{
		t_vec3 *vec = at_vector(&obj.vertex_normals, i);
		printf("normal %lf %lf %lf\n", vec->x, vec->y, vec->z);
		++i;
	}
	i = 0;
	while (i < obj.space_vertices.size)
	{
		t_vec3 *vec = at_vector(&obj.vertices, i);
		printf("space %lf %lf %lf\n", vec->x, vec->y, vec->z);
		++i;
	}
	i = 0;
	while (i < obj.faces.size)
	{
		t_polygon *face = at_vector(&obj.faces, i);
		printf("face %ld/%ld/%ld %ld/%ld/%ld %ld/%ld/%ld\n", face->points[0].vertice_id, face->points[0].texture_id, face->points[0].normal_id, face->points[1].vertice_id, face->points[1].texture_id, face->points[1].normal_id, face->points[2].vertice_id, face->points[2].texture_id, face->points[2].normal_id);
		++i;
	}
	if (argc == 1)
		return (0);
	if (init_engine(&engine, argv[1]) == -1)
		return (1);
	i = 0;
	while (i < engine.scene.objects.size)
	{
		t_object	*bolide = at_vector(&engine.scene.objects, i);
		if (bolide->type == MESH)
			bolide->data.mesh.obj_3d = &obj;
		++i;
	}
	printf("finish init : obj count is %ld\n", engine.scene.objects.size);
	run_loop(&engine);
	clear_engine(&engine);
	return (0);
}
