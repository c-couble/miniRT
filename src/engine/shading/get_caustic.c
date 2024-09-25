/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_caustic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:06:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/25 07:08:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "density.h"
#include "kdtree.h"
#include "photon.h"
#include "color.h"
#include "ray.h"
#include "shading.h"
#include <stdio.h>

int get_caustic(t_engine *eng, t_ray *c_ray, t_kdtree *tree, t_color *light)
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
	caustic.color = knn.querys[0].node->photon.color.color;
	estimate = density_estimation(&knn, eng->bandwidth) * 100;
	caustic.color = scale_color(&caustic, estimate);
	printf("estimate: %lf\n", estimate);
	light->color = caustic.color;
	clear_knn(&knn);
	return (0);
}
