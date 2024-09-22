/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_knn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:11:51 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 23:12:23 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <stdlib.h>
#include "kdtree.h"

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
