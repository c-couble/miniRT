/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_obj_cache.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 02:53:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/28 02:39:23 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "mat4.h"
#include "obj_3d.h"
#include "object/mesh.h"
#include "object/triangle.h"
#include "vec3.h"
#include "vec4.h"
#include <stdio.h>
#include <stdlib.h>

static	void	get_matrix(t_mesh *mesh, t_mat4 *matrix);
static	void	cache_point(t_mesh *mesh, t_mat4 *mat, size_t face, int i);
static	void	finish_polygon(t_cached_triangle *t);
static void	set_mesh_tri_aabb(t_mesh *mesh);

int	build_obj_cache(t_mesh *mesh)
{
	size_t		i;
	t_polygon	*polygon;
	t_obj_3d	*obj;
	t_mat4		transformation;

	obj = mesh->obj_3d;
	mesh->cache = malloc(obj->faces.size * sizeof(t_cached_triangle));
	if (mesh->cache == NULL)
		return (-1);
	mesh->triangles = obj->faces.size;
	get_matrix(mesh, &transformation);
	i = 0;
	while (i < obj->faces.size)
	{
		polygon = at_vector(&obj->faces, i);
		cache_point(mesh, &transformation, i, 0);
		cache_point(mesh, &transformation, i, 1);
		cache_point(mesh, &transformation, i, 2);
		finish_polygon(mesh->cache + i);
		mesh->cache[i].material = polygon->material;
		++i;
	}
	set_mesh_tri_aabb(mesh);
	mesh->bvh = init_bvh_mesh(mesh->cache, mesh->triangles);
	if (mesh->bvh == NULL)
		return (-1);
	return (0);
}

static void	set_mesh_tri_aabb(t_mesh *mesh)
{
	size_t	i;

	i = 0;
	while (i < mesh->triangles)
	{
		get_cached_triangle_aabb(&mesh->cache[i], &mesh->cache[i].aabb);
		++i;
	}
}

static void	get_matrix(t_mesh *mesh, t_mat4 *matrix)
{
	t_mat4	scale;

	mat4_view(matrix, &mesh->front, &mesh->up, &mesh->pos);
	mat4_scale(&scale, mesh->scale, 1);
	mat4_multiply(&scale, matrix, matrix);
}

static void	cache_point(t_mesh *mesh, t_mat4 *mat, size_t face, int i)
{
	t_obj_3d			*obj;
	t_polygon			*p;
	t_cached_triangle	*c;
	t_vec4				v4;

	obj = mesh->obj_3d;
	p = at_vector(&obj->faces, face);
	c = mesh->cache + face;
	vec4_create(at_vector(&obj->vertices, p->points[i].vertice_id - 1), 1, &v4);
	vec4_mat4_mult(&v4, mat, &v4);
	c->points[i].x = v4.x;
	c->points[i].y = v4.y;
	c->points[i].z = v4.z;
	if (p->points[i].tx_id == (size_t) -1)
		c->point_tx[i] = NULL;
	else
		c->point_tx[i] = at_vector(&obj->tx_coords, p->points[i].tx_id - 1);
}

static void	finish_polygon(t_cached_triangle *t)
{
	vec3_subtract(&t->points[1], &t->points[0], &t->e1);
	vec3_subtract(&t->points[2], &t->points[0], &t->e2);
	vec3_cross(&t->e1, &t->e2, &t->normal);
	vec3_normalize(&t->normal);
}
