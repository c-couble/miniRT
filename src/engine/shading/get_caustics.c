/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_caustics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:06:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/29 23:06:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "shading.h"
#include <stdio.h>

static uint32_t	get_mean_color(t_knn *knn);
static void		get_caustic(t_caustic *c, t_ray *r, t_kdtree *tree, t_color *l);

void	get_caustics(t_caustic *caustic, t_ray *ray, t_color *light)
{
	size_t			i;
	t_caustic_map	*map;

	i = 0;
	map = caustic->caustic_maps.array;
	while (i < caustic->caustic_maps.size)
	{
		if (is_point_iside_aabb(&ray->data.hitpos, &map[i].aabb))
			get_caustic(caustic, ray, map[i].tree, light);
		++i;
	}
}

static void	get_caustic(t_caustic *c, t_ray *r, t_kdtree *tree, t_color *light)
{
	double		estimate;
	t_color		caustic;

	set_knn_size(&c->knn, c->nn);
	get_knearest_neighbour(&c->knn, tree, &r->data.hitpos);
	if (c->knn.nn_count == 0)
		return ;
	caustic.color = get_mean_color(&c->knn);
	estimate = density_estimation(&c->knn, c->bandwidth) * ESTIMATION_SCALE;
	caustic.color = scale_color(&caustic, estimate);
	light->color = add_color(light, &caustic);
	empty_knn(&c->knn);
}

static uint32_t	get_mean_color(t_knn *knn)
{
	size_t	i;
	size_t	r;
	size_t	g;
	size_t	b;
	t_color	ret;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	while (i < knn->nn_count)
	{
		r += knn->querys[i].node->photon.color.rgb.r;
		g += knn->querys[i].node->photon.color.rgb.g;
		b += knn->querys[i].node->photon.color.rgb.b;
		++i;
	}
	ret.rgb.r = r / i;
	ret.rgb.g = g / i;
	ret.rgb.b = b / i;
	return (ret.color);
}
