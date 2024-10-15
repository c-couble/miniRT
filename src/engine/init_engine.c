/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:33:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 16:34:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "defines.h"
#include "engine.h"
#include "caustic.h"
#include "texture.h"
#include "util.h"

static int	prepare_engine(t_engine *engine, char *scene);
static int	init_hooks(t_engine *engine);
static void	init_perspective(t_camera *camera, double ratio);
static void	init_projection(t_mat4 *inv, double ratio, double fov);

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
	init_projection(&engine->scene.camera.inv_projection,
		engine->mlx.aspect, engine->scene.camera.fov);
	if (engine->render_size != 0)
	{
		init_projection(&engine->scene.camera.inv_proj_file,
			engine->render_width / (double) engine->render_height,
			engine->scene.camera.fov);
	}
	init_perspective(&engine->scene.camera, engine->mlx.aspect);
	init_material(&engine->default_material);
	return (0);
}

static int	prepare_engine(t_engine *engine, char *scene)
{
	if (init_scene(engine, &engine->scene, scene) == -1)
		return (-1);
	engine->render_size = engine->render_width * engine->render_height;
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
	if (engine->render_size != 0)
	{
		engine->render_data = malloc(engine->render_size * sizeof(t_color));
		if (engine->render_data == NULL)
			return (-1);
	}
	return (0);
}

static void	init_projection(t_mat4 *inv, double ratio, double fov)
{
	const double	fov_rad = 1 / tan((fov * (M_PI / 180)) / 2);

	inv->matrix[0] = (1 / ratio) * fov_rad;
	inv->matrix[1] = 0;
	inv->matrix[2] = 0;
	inv->matrix[3] = 0;
	inv->matrix[4] = 0;
	inv->matrix[5] = 1;
	inv->matrix[6] = 0;
	inv->matrix[7] = 0;
	inv->matrix[8] = 0;
	inv->matrix[9] = 0;
	inv->matrix[10] = fov_rad;
	inv->matrix[11] = 0;
	inv->matrix[12] = 0;
	inv->matrix[13] = 0;
	inv->matrix[14] = 0;
	inv->matrix[15] = 1;
	mat4_inverse(inv, inv);
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
