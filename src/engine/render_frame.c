/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:55:37 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/15 09:11:11 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "defines.h"
#include "engine.h"
#include "mat4.h"
#include "object.h"
#include "object/camera.h"
#include "ray.h"
#include "vec4.h"
#include "vector.h"
#include "vec3.h"
#include "ft_math.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t	get_pixel_color(t_engine *engine, int x, int y, t_mat4 *inv_proj, t_mat4 *inv_view);
static void		setup_ray(t_engine *engine, t_ray *ray, int x, int y);
static void		setup_camera(t_camera *camera);

void	render_frame(t_engine *engine)
{
	size_t	i;
	size_t	j;
	

	i = 0;
	printf("START FRAME\n\n");
	setup_camera(&engine->scene.camera);
	while (i < engine->mlx.height)
	{
		j = 0;
		while (j < engine->mlx.width)
		{
			engine->mlx.addr[(i * engine->mlx.width) + j].color
				= get_pixel_color(engine, j, i, &engine->scene.camera.inverse_projection, &engine->scene.camera.inverse_view);
			++j;
		}
		++i;
	}
	printf("END FRAME\n\n");
}
static void	setup_view(t_camera *camera);

static void		setup_camera(t_camera *camera)
{
	const double near = 0.1;
	const double far = 100;
	const double fov_rad = 1 / tan((camera->fov * (M_PI / 180)) / 2);

	camera->projection.matrix[0] = (double) SCREEN_HEIGHT / SCREEN_WIDTH * fov_rad;
	camera->projection.matrix[1] = 0;
	camera->projection.matrix[2] = 0;
	camera->projection.matrix[3] = 0;
	camera->projection.matrix[4] = 0;
	camera->projection.matrix[5] = fov_rad;
	camera->projection.matrix[6] = 0;
	camera->projection.matrix[7] = 0;
	camera->projection.matrix[8] = 0;
	camera->projection.matrix[9] = 0;
	camera->projection.matrix[10] = far / (far - near);
	camera->projection.matrix[11] = - (far * near) / (far - near);
	camera->projection.matrix[12] = 0;
	camera->projection.matrix[13] = 0;
	camera->projection.matrix[14] = 1;
	camera->projection.matrix[15] = 0;
	camera->inverse_projection = camera->projection;
	printf("PROJ MATRIX\n");
	mat4_print(&camera->projection);
	printf("END PROJ MATRIX\n");
	printf("START INVERSION\n");
	mat4_inverse(&camera->projection, &camera->inverse_projection);
	printf("END INVERSION\n");
	printf("INVERSE PROJ\n");
	mat4_print(&camera->inverse_projection);
	printf("INVERSE END\n");

	setup_view(camera);
}

static void	setup_view(t_camera *camera)
{
	t_vec3	up;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	target;

	target = camera->orientation;
	vec3_create(0, 0, 1, &up);
	forward = target;
	vec3_scale(&forward, -1);
	vec3_cross_product(&up, &forward, &right);
	camera->view.matrix[0] = right.x;
	camera->view.matrix[1] = forward.x;
	camera->view.matrix[2] = up.x;
	camera->view.matrix[3] = camera->coordinates.x;
	camera->view.matrix[4] = right.y;
	camera->view.matrix[5] = forward.y;
	camera->view.matrix[6] = up.y;
	camera->view.matrix[7] = camera->coordinates.y;
	camera->view.matrix[8] = right.z;
	camera->view.matrix[9] = forward.z;
	camera->view.matrix[10] = up.z;
	camera->view.matrix[11] = camera->coordinates.z;
	camera->view.matrix[12] = 0;
	camera->view.matrix[13] = 0;
	camera->view.matrix[14] = 0;
	camera->view.matrix[15] = 1;
	printf("VIEW MATRIX\n");
	mat4_print(&camera->view);
	printf("END VIEW MATRIX\n");
	printf("START INVERSION\n");
	mat4_inverse(&camera->view, &camera->inverse_view);
	printf("END INVERSION\n");
	printf("INVERSE\n");
	mat4_print(&camera->inverse_view);
	printf("INVERSE END\n");
}

static void	setup_ray(t_engine *engine, t_ray *ray, int x, int y)
{
	//double	ratio = engine->mlx.width / (double) engine->mlx.height;
	double	px = 2 * ((x + 0.5) / engine->mlx.width) - 1;
	double	py = 1 - 2 * (y + 0.5) / engine->mlx.height;
	ray->ray.x = px;
	ray->ray.y = -1;
	ray->ray.z = py;
	vec3_normalize(&ray->ray);
	ray->startpos = engine->scene.camera.coordinates;
}

static uint32_t	get_pixel_color(t_engine *engine, int x, int y, t_mat4 *inv_proj, t_mat4 *inv_view)
{
	t_ray	ray;
	t_color	color;
	t_color	light;

	setup_ray(engine, &ray, x, y);
	if (x == SCREEN_WIDTH / 2 && y == SCREEN_HEIGHT / 2)
		printf("x=%lf y=%lf z=%lf\n", ray.ray.x, ray.ray.y, ray.ray.z);
	t_vec3 a;
	t_vec4	final;
	vec4_create(&ray.ray, 1, &final);
	vec4_mat4_mult(&final, &engine->scene.camera.inverse_projection, &final);
	final.x /= final.w;
	final.y /= final.w;
	final.z /= final.w;
	final.w = 0;
	vec3_normalize(&a);
	ray.ray = a;
	(void)inv_proj;

	a.x = ray.ray.x * inv_view->matrix[0]
		+ ray.ray.y * inv_view->matrix[1]
		+ ray.ray.z * inv_view->matrix[2];
	a.y = ray.ray.x * inv_view->matrix[4]
		+ ray.ray.y * inv_view->matrix[5]
		+ ray.ray.z * inv_view->matrix[6];
	a.z = ray.ray.x * inv_view->matrix[8]
		+ ray.ray.y * inv_view->matrix[9]
		+ ray.ray.z * inv_view->matrix[10];
	ray.ray = a;
	vec3_normalize(&ray.ray);
		printf("x=%lf y=%lf z=%lf\n", ray.ray.x, ray.ray.y, ray.ray.z);
	if (trace_ray(engine, &ray) > 0)
	{
		color = ray.data.color;
		light = get_light(engine, &ray);
		return (color.color & light.color);
	}
	return (0);
}
