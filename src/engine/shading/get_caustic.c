/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_caustic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:06:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/24 17:17:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "density.h"
#include "kdtree.h"
#include "object/light.h"
#include "photon.h"
#include "color.h"
#include "ray.h"
#include "shading.h"
#include <stdio.h>

int get_caustic(t_engine *eng, t_ray *c_ray, t_kdtree *tree, t_color *light)
{
	t_light		caustic;
	t_ray		p_ray;
	t_knn		knn;

	if (init_knn(&knn, eng->nn) == -1)
		return (-1);
	get_knearest_neighbour(&knn, tree, &c_ray->data.hitpos);
	if (knn.count == 0)
	{
		clear_knn(&knn);
		return (0);
	}
//	print_knn(&knn);
	caustic.pos = c_ray->data.hitpos;
	caustic.color = knn.querys[0].node->photon.color;
	caustic.ratio = density_estimation(&knn, eng->bandwidth);
//	printf("estimation : %lf\n", caustic.ratio);
	p_ray.startpos = knn.querys[0].node->photon.origin;
	p_ray.ray = c_ray->data.hitpos;
	phong_model(&caustic, light, c_ray, &p_ray);
	clear_knn(&knn);
	return (0);
}
