/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_caustic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:06:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 06:16:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caustic.h"
#include "float.h"
#include "density.h"
#include "kdtree.h"
#include "photon.h"
#include "color.h"
#include "ray.h"
#include "shading.h"
#include <stdint.h>
#include <stdio.h>

static uint32_t	get_mean_color(t_knn *knn);
int get_caustic2(t_engine *eng, t_ray *c_ray, t_kdtree *tree, t_color *light);

int	get_caustic(t_engine *eng, t_ray *ray, t_color *light)
{
	size_t			i;
	t_caustic_map	*map;

	i = 0;
	map = eng->caustic_maps.array;
	while (i < eng->caustic_maps.size)
	{
		if (get_caustic2(eng, ray, map[i].tree, light) == -1)
			return (-1);
		++i;
	}
	return (0);
}

int get_caustic2(t_engine *eng, t_ray *c_ray, t_kdtree *tree, t_color *light)
{
	double		estimate;
	t_knn		knn;
	t_color		caustic;

	if (init_knn(&knn, eng->nn) == -1)
		return (-1);
	get_knearest_neighbour(&knn, tree, &c_ray->data.hitpos);
	if (knn.count == 0)
	{
		clear_knn(&knn);
		return (0);
	}
	caustic.color = get_mean_color(&knn);
	estimate = density_estimation(&knn, eng->bandwidth) * 100;
	caustic.color = scale_color(&caustic, estimate);
	printf("estimate: %lf\n", estimate);
	light->color = add_color(light, &caustic);
	clear_knn(&knn);
	return (0);
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
	while (i < knn->count)
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
