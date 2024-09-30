/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_knn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:16:39 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 21:54:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "kdtree.h"
#include "vec3.h"
#include "vector.h"
#include <stdio.h>

void	print_knn(t_knn *knn)
{
	size_t	i;

	i = 0;
	printf("knn.count :%ld, knn.size :%ld\n", knn->nn_count, knn->nn_size);
	printf("knn.farest :%ld\n", knn->farest_idx);
	while (i < knn->nn_size)
	{
		if (knn->querys[i].dist == DBL_MAX)
		{
			printf("knn[%ld].query : EMPTY\n", i);
		}
		else
		{
			printf("knn[%ld].query.pos :", i);
			vec3_print(&knn->querys[i].node->photon.pos, "pos");
			printf("knn[%ld].query.dist : %lf\n", i, knn->querys[i].dist);
		}
		++i;
	}
}
