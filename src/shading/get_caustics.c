/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_caustics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:06:37 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:20:17 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "shading.h"

static t_colorf	get_mean_color(t_knn *knn);
static void		get_caustic(t_caustic *c, t_ray *r, t_kdtree *tr, t_colorf *l);

void	get_caustics(t_caustic *caustic, t_ray *ray, t_colorf *light)
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

static void	get_caustic(t_caustic *c, t_ray *r, t_kdtree *tree, t_colorf *light)
{
	double		estimate;
	t_colorf	caustic;

	set_knn_size(&c->knn[r->t_id], c->nn_nb);
	get_knearest_neighbour(&c->knn[r->t_id], tree, &r->data.hitpos);
	if (c->knn[r->t_id].nn_count == 0)
		return ;
	caustic = get_mean_color(&c->knn[r->t_id]);
	estimate = density_estimation(&c->knn[r->t_id], c->bandwidth);
	estimate *= c->intensity_scalar;
	caustic = color_scale(caustic, estimate);
	*light = color_add(*light, caustic);
	empty_knn(&c->knn[r->t_id]);
}

static t_colorf	get_mean_color(t_knn *knn)
{
	size_t		i;
	float		r;
	float		g;
	float		b;
	t_colorf	ret;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	while (i < knn->nn_count)
	{
		r += knn->querys[i].node->photon.color.r;
		g += knn->querys[i].node->photon.color.g;
		b += knn->querys[i].node->photon.color.b;
		++i;
	}
	ret.r = r / i;
	ret.g = g / i;
	ret.b = b / i;
	return (ret);
}
