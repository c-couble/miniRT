/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   density_estimation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:09:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 06:40:50 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kdtree.h"
#include <math.h>

double	kernel_gaussian_3d(double dist, double bandwidth)
{
	const double	normal = 1.0 / pow(2 * M_PI, 1.5) * pow(bandwidth, 3);
	const double	exponant = exp(-dist / (2 * (bandwidth * bandwidth)));

	return (normal * exponant);
}

double	density_estimation(t_knn *knn, double bandwidth)
{
	const double	volume = (4.0 / 3.0) * M_PI * pow(bandwidth, 3);
	double			estimation;
	double			kernel;
	size_t			i;

	i = 0;
	estimation = 0;
	while (i < knn->count)
	{
		kernel = kernel_gaussian_3d(knn->querys[i].dist, bandwidth);
		estimation += kernel * knn->querys[i].node->photon.ratio;
		++i;
	}
	return (estimation / (knn->count * volume));
}
