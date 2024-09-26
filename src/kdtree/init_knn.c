/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_knn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:11:51 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 00:41:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <stdlib.h>
#include "defines.h"
#include "kdtree.h"

int init_knn(t_knn *knn, size_t k)
{
	size_t	i;

	knn->querys = malloc(sizeof(t_query) * KNN_MAX);
	if (knn->querys == NULL)
		return (-1);
	knn->count = 0;
	knn->size = k;
	knn->max_size = KNN_MAX;
	knn->farest = 0;
	i = 0;
	while (i < knn->max_size)
	{
		knn->querys[i].node = NULL;
		knn->querys[i].dist = DBL_MAX;
		++i;
	}
	return (0);
}
