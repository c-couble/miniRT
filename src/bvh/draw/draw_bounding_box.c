/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bounding_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:29:55 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/14 07:48:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "defines.h"
#include "draw.h"
#include "vec2.h"
#include "engine.h"
#include "vec3.h"
#include "vec4.h"

static void	world_to_screen(t_camera *camera, t_vec3 *in, t_vec2 *out);

void	draw_bounding_box(t_engine *eng, t_bbox *box, uint32_t color)
{
	t_vec2	top[4];
	t_vec2	bottom[4];

	world_to_screen(&eng->scene.camera, &box->top[0], &top[0]);
	world_to_screen(&eng->scene.camera, &box->top[1], &top[1]);
	world_to_screen(&eng->scene.camera, &box->top[2], &top[2]);
	world_to_screen(&eng->scene.camera, &box->top[3], &top[3]);
	world_to_screen(&eng->scene.camera, &box->bottom[0], &bottom[0]);
	world_to_screen(&eng->scene.camera, &box->bottom[1], &bottom[1]);
	world_to_screen(&eng->scene.camera, &box->bottom[2], &bottom[2]);
	world_to_screen(&eng->scene.camera, &box->bottom[3], &bottom[3]);
	draw_line(eng, &top[0], &top[1], &color);
	draw_line(eng, &top[1], &top[2], &color);
	draw_line(eng, &top[2], &top[3], &color);
	draw_line(eng, &top[3], &top[0], &color);
	draw_line(eng, &top[0], &bottom[0], &color);
	draw_line(eng, &top[1], &bottom[1], &color);
	draw_line(eng, &top[2], &bottom[2], &color);
	draw_line(eng, &top[3], &bottom[3], &color);
	draw_line(eng, &bottom[0], &bottom[1], &color);
	draw_line(eng, &bottom[1], &bottom[2], &color);
	draw_line(eng, &bottom[2], &bottom[3], &color);
	draw_line(eng, &bottom[3], &bottom[0], &color);
}

static void	world_to_screen(t_camera *camera, t_vec3 *in, t_vec2 *out)
{
	t_vec4	world;
	t_vec4	screen_space;
	double	x;
	double	y;

	vec4_create(in, 1, &world);
	vec4_substract_vec3(&world, &camera->coordinates, &world);
	vec4_mat4_mult(&world, &camera->view, &screen_space);
	vec4_mat4_mult(&screen_space, &camera->perspective, &screen_space);
	if (screen_space.w > 0)
		vec4_divide_nw(&screen_space, screen_space.w, &screen_space);
	else
	{
		out->x = -1;
		out->y = -1;
		return ;
	}
	x = screen_space.x + 1;
	y = 1 - screen_space.y;
	out->x = x * camera->frame_width * 0.5;
	out->y = y * camera->frame_height * 0.5;
}
