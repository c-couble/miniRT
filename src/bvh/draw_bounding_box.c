/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bounding_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:50:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/12 20:36:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"
#include "vec2.h"
#include "engine.h"
#include <stdio.h>

int	draw_bounding_box(t_engine *eng)
{
	size_t		i;
	t_object	*obj;
	t_vec2		a;
	t_vec2		b;

	i = 0;
	while (i < eng->scene.objects.size)
	{
		obj = at_vector(&eng->scene.objects, i);
		if (obj->type == SPHERE)
		{
			printf("sphere pos x: %lf, y: %lf, z:%lf | radius = %lf\n",
				obj->data.sphere.pos.x, obj->data.sphere.pos.y,
		  	obj->data.sphere.pos.z, obj->data.sphere.radius);
			print_aabb(&obj->aabb, "sphere aabb");
			print_bounding_box(&obj->aabb.box);
		}
		if (obj->type == CYLINDER)
		{
			printf("cyl pos x: %lf, y: %lf, z:%lf | radius = %lf\n",
				obj->data.cylinder.pos.x, obj->data.cylinder.pos.y,
		  	obj->data.cylinder.pos.z, obj->data.cylinder.radius);
			print_aabb(&obj->aabb, "cyl aabb");
			print_bounding_box(&obj->aabb.box);
		}
		if (obj->type == PARABOLOID)
		{
			printf("para pos x: %lf, y: %lf, z:%lf | radius = %lf\n",
				obj->data.paraboloid.pos.x, obj->data.paraboloid.pos.y,
		  	obj->data.paraboloid.pos.z, obj->data.paraboloid.radius);
			print_aabb(&obj->aabb, "para aabb");
			print_bounding_box(&obj->aabb.box);
		}
		++i;
	}
	(void)a;
	(void)b;
	/*
	for (size_t i = 0; i <= eng->scene.camera.frame_height; ++ i)
	{
		a.x = 0;
		a.y = i;
		b.x = eng->scene.camera.frame_width;
		b.y = i;
		draw_line(eng, &a, &b);
	}
	*/
	return (0);
}
