/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:12:59 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/11 02:34:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "engine.h"
#include "shading.h"

uint32_t	render_pixel(t_engine *engine, t_ray *c_ray, int w, int h)
{
	t_colorf	n_color;
	t_colorf	*sample;

	n_color = shade_ray(&engine->scene, c_ray, DEPTH);
	if (engine->sampling == 0)
		return (color_denormalize(n_color));
	sample = &engine->samples[(h * (engine->mlx.width + 1)) + w];
	sample->r += n_color.r;
	sample->g += n_color.g;
	sample->b += n_color.b;
	n_color.r = sample->r / engine->sample_nb;
	n_color.g = sample->g / engine->sample_nb;
	n_color.b = sample->b / engine->sample_nb;
	return (color_denormalize(n_color));
}

uint32_t	render_low_quality_pixel(t_engine *engine, t_ray *c_ray)
{
	t_colorf	n_color;

	n_color = shade_ray(&engine->scene, c_ray, LOW_RENDER_DEPTH);
	return (color_denormalize(n_color));
}
