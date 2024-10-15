/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_knn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:11:51 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 10:58:02 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <stdlib.h>
#include "kdtree.h"

int	init_knn(t_knn *knn, size_t k, size_t knn_max)
{
	size_t	i;

	knn->querys = malloc(sizeof(t_query) * knn_max);
	if (knn->querys == NULL)
		return (-1);
	knn->nn_count = 0;
	knn->nn_size = k;
	knn->farest_idx = 0;
	i = 0;
	while (i < knn_max)
	{
		knn->querys[i].node = NULL;
		knn->querys[i].dist = DBL_MAX;
		++i;
	}
	return (0);
}
