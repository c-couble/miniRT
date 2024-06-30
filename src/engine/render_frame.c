/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/28 01:26:41 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "mat4.h"
#include "object.h"
#include "ray.h"
#include "vector.h"
#include "vec3.h"
#include "ft_math.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t	get_pixel_color(t_engine *engine, int x, int y, t_mat4 *cam);
static void		setup_ray(t_engine *engine, t_ray *ray, int x, int y);

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	t_vec3	up;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	target;
	

	target = engine->scene.camera.orientation;
	vec3_create(0, 0, 1, &up);
	forward = target;
	vec3_scale(&forward, -1);
	vec3_cross_product(&up, &forward, &right);
	i = 0;
	printf("START FRAME\n\n");
	t_mat4	mat;
	mat.matrix[0] = right.x;
	mat.matrix[1] = forward.x;
	mat.matrix[2] = up.x;
	mat.matrix[3] = engine->scene.camera.coordinates.x;
	mat.matrix[4] = right.y;
	mat.matrix[5] = forward.y;
	mat.matrix[6] = up.y;
	mat.matrix[7] = engine->scene.camera.coordinates.y;
	mat.matrix[8] = right.z;
	mat.matrix[9] = forward.z;
	mat.matrix[10] = up.z;
	mat.matrix[11] = engine->scene.camera.coordinates.z;
	mat.matrix[12] = 0;
	mat.matrix[13] = 0;
	mat.matrix[14] = 0;
	mat.matrix[15] = 1;
	mat4_print(&mat);
	while (i < engine->mlx.height)
	{
		j = 0;
		while (j < engine->mlx.width)
		{
			engine->mlx.addr[(i * engine->mlx.width) + j].color
				= get_pixel_color(engine, j, i, &mat);
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
}

static void	setup_ray(t_engine *engine, t_ray *ray, int x, int y)
{
	double	ratio = engine->mlx.width / (double) engine->mlx.height;
	double	px = (2 * ((x + 0.5) / engine->mlx.width) - 1) * tan(engine->scene.camera.fov / 2 * M_PI / 180) * ratio;
	double	py = (1 - 2 * (y + 0.5) / engine->mlx.height) * tan(engine->scene.camera.fov / 2 * M_PI / 180);
	ray->ray.x = px;
	ray->ray.y = -1;
	ray->ray.z = py;
	vec3_normalize(&ray->ray);
	ray->startpos = engine->scene.camera.coordinates;
}

static uint32_t	get_pixel_color(t_engine *engine, int x, int y, t_mat4 *cam)
{
	t_ray	ray;
	t_color	color;
	t_color	light;

	setup_ray(engine, &ray, x, y);
	if (x == SCREEN_WIDTH / 2 && y == SCREEN_HEIGHT / 2)
		printf("x=%lf y=%lf z=%lf\n", ray.ray.x, ray.ray.y, ray.ray.z);
	t_vec3 a;
	a.x = ray.ray.x * cam->matrix[0]
		+ ray.ray.y * cam->matrix[1]
		+ ray.ray.z * cam->matrix[2];
	a.y = ray.ray.x * cam->matrix[4]
		+ ray.ray.y * cam->matrix[5]
		+ ray.ray.z * cam->matrix[6];
	a.z = ray.ray.x * cam->matrix[8]
		+ ray.ray.y * cam->matrix[9]
		+ ray.ray.z * cam->matrix[10];
	ray.ray = a;
	if (x == SCREEN_WIDTH / 2 && y == SCREEN_HEIGHT / 2)
		printf("x=%lf y=%lf z=%lf\n", ray.ray.x, ray.ray.y, ray.ray.z);
	if (trace_ray(engine, &ray) > 0)
	{
		color = ray.data.color;
		light = get_light(engine, &ray);
		return (color.color & light.color);
	}
	return (0);
}
