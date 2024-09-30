/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_knn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:54:50 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 21:54:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "kdtree.h"

void	empty_knn(t_knn *knn)
{
	size_t	i;

	i = 0;
	while (i < knn->nn_count)
	{
		knn->querys[i].node = NULL;
		knn->querys[i].dist = DBL_MAX;
		++i;
	}
	knn->nn_count = 0;
	knn->farest_idx = 0;
}
