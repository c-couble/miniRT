/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bounding_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:50:18 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/13 20:05:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "ft_math.h"
#include "mat4.h"
#include "object.h"
#include "object/camera.h"
#include "vec2.h"
#include "engine.h"
#include "vec3.h"
#include "vec4.h"
#include <stdio.h>

void	debug(t_object *obj);

void	world_to_screen(t_camera *camera, t_vec3 *in, t_vec2 *out)
{
	t_vec4	world;
	t_vec4	screen_space;
	double	x;
	double	y;

	world.x = in->x;
	world.y = in->y;
	world.z = in->z;
	world.w = 1;
	printf("world.x = %lf\n",  world.x);
	printf("world.y = %lf\n",  world.y);
	printf("world.z = %lf\n",  world.z);
	printf("world.w = %lf\n",  world.w);
	vec4_mat4_mult(&world, &camera->view, &screen_space);
	vec4_mat4_mult(&screen_space, &camera->projection, &screen_space);
	if (screen_space.w > 0)
	{
		screen_space.x = screen_space.x / screen_space.w;
		screen_space.y = screen_space.y / screen_space.w;
		screen_space.z = screen_space.z / screen_space.w;
	}
	else
	{
		printf("w = %lf return\n", screen_space.w);
		out->x = -1;
		out->y = -1;
		return ;
	}
	printf("screen.x = %lf\n",  screen_space.x);
	printf("screen.y = %lf\n",  screen_space.y);
	printf("screen.z = %lf\n",  screen_space.z);
	printf("screen.w = %lf\n",  screen_space.w);
	x = screen_space.x;
	y = screen_space.y;
	x = (x + 1);
	y = (1 - y);
	x = x * camera->frame_width * 0.5;
	y = y * camera->frame_height * 0.5;
	printf("screen width = %ld\n", camera->frame_width);
	printf("screen height = %ld\n", camera->frame_height);
	out->x = x;
	out->y = y;
}

void draw_box(t_engine *eng, t_bbox *box)
{
	t_vec2	top[4];
	t_vec2	bottom[4];

	t_vec3 origine;
	vec3_create(10, 0, 0, &origine);
	t_vec2 screen_origine;
	world_to_screen(&eng->scene.camera, &origine, &screen_origine);
	printf("screen origin x=  %d | y = %d\n", screen_origine.x, screen_origine.y);
	print_bounding_box(box);
	world_to_screen(&eng->scene.camera, &box->top[0], &top[0]);
	world_to_screen(&eng->scene.camera, &box->top[1], &top[1]);
	world_to_screen(&eng->scene.camera, &box->top[2], &top[2]);
	world_to_screen(&eng->scene.camera, &box->top[3], &top[3]);
	world_to_screen(&eng->scene.camera, &box->bottom[0], &bottom[0]);
	world_to_screen(&eng->scene.camera, &box->bottom[1], &bottom[1]);
	world_to_screen(&eng->scene.camera, &box->bottom[2], &bottom[2]);
	world_to_screen(&eng->scene.camera, &box->bottom[3], &bottom[3]);
	printf("top[0].x: %d, top[0].y: %d\n",top[0].x, top[0].y);
	printf("top[1].x: %d, top[1].y: %d\n",top[1].x, top[1].y);
	printf("top[2].x: %d, top[2].y: %d\n",top[2].x, top[2].y);
	printf("top[3].x: %d, top[3].y: %d\n",top[3].x, top[3].y);
	printf("bottom[0].x: %d, bottom[0].y: %d\n",bottom[0].x, bottom[0].y);
	printf("bottom[1].x: %d, bottom[1].y: %d\n",bottom[1].x, bottom[1].y);
	printf("bottom[2].x: %d, bottom[2].y: %d\n",bottom[2].x, bottom[2].y);
	printf("bottom[3].x: %d, bottom[3].y: %d\n",bottom[3].x, bottom[3].y);
	draw_line(eng, &top[0], &top[1]);
	draw_line(eng, &top[1], &top[2]);
	draw_line(eng, &top[2], &top[3]);
	draw_line(eng, &top[3], &top[0]);
	draw_line(eng, &top[0], &bottom[0]);
	draw_line(eng, &top[1], &bottom[1]);
	draw_line(eng, &top[2], &bottom[2]);
	draw_line(eng, &top[3], &bottom[3]);
	draw_line(eng, &bottom[0], &bottom[1]);
	draw_line(eng, &bottom[1], &bottom[2]);
	draw_line(eng, &bottom[2], &bottom[3]);
	draw_line(eng, &bottom[3], &bottom[0]);
}

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
		if (obj->type != PLANE)
			draw_box(eng, &obj->aabb.box);
		debug(obj);
		++i;
	}
	(void)a;
	(void)b;
	/*
	for (size_t i = 0; i <= eng->scene.camera.frame_height / 2; ++ i)
	{
		a.x = 0;
		a.y = i;
		b.x = eng->scene.camera.frame_width / 2;
		b.y = i;
		draw_line(eng, &a, &b);
	}*/
	return (0);
}

void	debug(t_object *obj)
{
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
}
