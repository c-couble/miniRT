/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_caustic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:06:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:19:13 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "defines.h"
#include "kdtree.h"
#include "photon.h"
#include "color.h"
#include "object/light.h"
#include "ray.h"
#include "shading.h"
#include "object.h"

int init_knn(t_knn *knn, size_t k)
{
	size_t	i;

	knn->querys = malloc(sizeof(t_query) * k);
	if (knn->querys == NULL)
		return (-1);
	knn->count = 0;
	knn->size = k;
	knn->farest = 0;
	i = 0;
	while (i < k)
	{
		knn->querys[i].node = NULL;
		knn->querys[i].dist = DBL_MAX;
		++i;
	}
	return (0);
}

void	get_caustic(t_ray *c_ray, t_kdtree *photons, t_color *light)
{
	t_object	obj;
	t_ray		photon_ray;
	double		norm;
	t_knn		knn;

	if (init_knn(&knn, 5) == -1)
		return ;
	get_knearest_neighbour(&knn, photons, &c_ray->data.hitpos);
//	print_knn(&knn);
	for (size_t i = 0; i < knn.count; ++i)
	{
		norm = sqrtf(knn.querys[i].dist);
		photon_ray.startpos = c_ray->startpos;
		photon_ray.ray = knn.querys[i].node->photon.pos;
		photon_ray.data.color.color = knn.querys[i].node->photon.color.color;
		if (norm < PHOTON_RADIUS)
		{
			obj.data.light.pos = photon_ray.startpos;
			obj.data.light.color = photon_ray.data.color;
			obj.data.light.ratio = knn.querys[i].node->photon.ratio;
			phong_model(&obj.data.light, light, c_ray, &photon_ray);
		}
	}
}
