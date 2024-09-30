/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:33:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 10:39:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <pthread.h>
#include <sched.h>
#include <stdlib.h>
#include "defines.h"
#include "engine.h"
#include "mlx_wrapper.h"
#include "obj_3d.h"
#include "obj_mtl.h"
#include "scene.h"
#include "caustic.h"
#include "texture.h"
#include "util.h"
#include "vector.h"

static int	prepare_engine(t_engine *engine, char *scene);
static int	init_hooks(t_engine *engine);
static void	init_perspective(t_camera *camera, double ratio);
static void	init_projection(t_camera *cam, double ratio);

int	init_engine(t_engine *engine, char *scene)
{
	init_vector(&engine->objs_3d, sizeof(t_obj_3d *));
	init_vector(&engine->obj_mtls, sizeof(t_obj_mtl *));
	init_vector(&engine->textures, sizeof(t_texture *));
	engine->render_width = 0;
	engine->render_height = 0;
	if (prepare_engine(engine, scene) == -1)
	{
		clear_textures(&engine->textures);
		clear_mtls(&engine->obj_mtls);
		clear_objs_3d(&engine->objs_3d);
		return (-1);
	}
	init_projection(&engine->scene.camera, engine->mlx.aspect);
	init_perspective(&engine->scene.camera, engine->mlx.aspect);
	init_material(&engine->default_material);
	return (0);
}

static int	prepare_engine(t_engine *engine, char *scene)
{
	if (init_scene(engine, &engine->scene, scene) == -1)
	{
		clear_scene(&engine->scene);
		return (-1);
	}
	if (init_mlx_struct(&engine->mlx) == -1)
	{
		clear_scene(&engine->scene);
		return (-1);
	}
	if (init_hooks(engine) == -1 || init_threads(engine) == -1)
	{
		clear_scene(&engine->scene);
		clear_mlx_struct(&engine->mlx);
		return (-1);
	}
	return (0);
}

static int	init_hooks(t_engine *engine)
{
	t_hook	hook;

	if (init_camera_hooks(engine) == -1)
		return (-1);
	if (init_bvh_hooks(engine) == -1)
		return (-1);
	if (init_caustic_hooks(engine) == -1)
		return (-1);
	hook = create_mlx_hook(engine_focus_in, engine, 0, FOCUS_IN);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(quit_engine, engine, KEY_ESCAPE, PRESS);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	hook = create_mlx_hook(quit_engine, engine, 0, DESTROY);
	if (add_vector(&engine->mlx.hooks, &hook, 1) == -1)
		return (-1);
	size_t	size = engine->render_height * engine->render_width;
	if (engine->render_width != 0 && engine->render_height != 0)
	{
		engine->render_data = malloc(size * sizeof(t_color));
		if (engine->render_data == NULL)
			return (-1);
	}
	return (0);
}

static void	init_projection(t_camera *cam, double ratio)
{
	const double	fov_rad = 1 / tan((cam->fov * (M_PI / 180)) / 2);

	cam->projection.matrix[0] = (1 / ratio) * fov_rad;
	cam->projection.matrix[1] = 0;
	cam->projection.matrix[2] = 0;
	cam->projection.matrix[3] = 0;
	cam->projection.matrix[4] = 0;
	cam->projection.matrix[5] = 1;
	cam->projection.matrix[6] = 0;
	cam->projection.matrix[7] = 0;
	cam->projection.matrix[8] = 0;
	cam->projection.matrix[9] = 0;
	cam->projection.matrix[10] = fov_rad;
	cam->projection.matrix[11] = 0;
	cam->projection.matrix[12] = 0;
	cam->projection.matrix[13] = 0;
	cam->projection.matrix[14] = 0;
	cam->projection.matrix[15] = 1;
	cam->inverse_projection = cam->projection;
	mat4_inverse(&cam->projection, &cam->inverse_projection);
}

static void	init_perspective(t_camera *camera, double ratio)
{
	const double	fov_rad = camera->fov * (M_PI / 180.0);
	const double	tan_half_fov = tan(fov_rad / 2.0);
	const double	far = FAR_PLANE;
	const double	near = NEAR_PLANE;
	const double	far_minus_near = far - near;

	camera->perspective.matrix[0] = 1.0 / (ratio * tan_half_fov);
	camera->perspective.matrix[1] = 0.0;
	camera->perspective.matrix[2] = 0.0;
	camera->perspective.matrix[3] = 0.0;
	camera->perspective.matrix[4] = 0.0;
	camera->perspective.matrix[5] = 0.0;
	camera->perspective.matrix[6] = -far / far_minus_near;
	camera->perspective.matrix[7] = -far * near / far_minus_near;
	camera->perspective.matrix[8] = 0.0;
	camera->perspective.matrix[9] = 1.0 / tan_half_fov;
	camera->perspective.matrix[10] = 0.0;
	camera->perspective.matrix[11] = 0.0;
	camera->perspective.matrix[12] = 0.0;
	camera->perspective.matrix[13] = 0.0;
	camera->perspective.matrix[14] = -1.0;
	camera->perspective.matrix[15] = 0.0;
}
