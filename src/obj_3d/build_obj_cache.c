/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_obj_cache.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 02:53:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/25 05:53:03 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_3d.h"

static void	cache_point(t_obj_3d *obj, t_polygon *p, int i);
static void	finish_polygon(t_cached_triangle *t);

void	build_obj_cache(t_obj_3d *obj)
{
	size_t		i;
	t_polygon	*polygon;

	i= 0;
	while (i < obj->faces.size)
	{
		polygon = at_vector(&obj->faces, i);
		cache_point(obj, polygon, 0);
		cache_point(obj, polygon, 1);
		cache_point(obj, polygon, 2);
		finish_polygon(&polygon->cache);
		polygon->cache.material = polygon->material;
		++i;
	}
}

static void	cache_point(t_obj_3d *obj, t_polygon *p, int i)
{
	p->cache.points[i] = at_vector(&obj->vertices, p->points[i].vertice_id - 1);
	if (p->points[i].texture_id == (size_t) -1)
		p->cache.point_texture[i] = NULL;
	else
		p->cache.point_texture[i] =
			at_vector(&obj->texture_coordinates, p->points[i].texture_id - 1);
}

static void	finish_polygon(t_cached_triangle *t)
{
	vec3_subtract(t->points[1], t->points[0], &t->e1);
	vec3_subtract(t->points[2], t->points[0], &t->e2);
	vec3_cross(&t->e1, &t->e2, &t->normal);
	vec3_normalize(&t->normal);
}
