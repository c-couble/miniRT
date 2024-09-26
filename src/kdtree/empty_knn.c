/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_knn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:54:50 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 00:42:04 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "kdtree.h"

void	empty_knn(t_knn *knn)
{
	size_t	i;

	i = 0;
	while (i < knn->count)
	{
		knn->querys[i].node = NULL;
		knn->querys[i].dist = DBL_MAX;
		++i;
	}
	knn->count = 0;
	knn->farest = 0;
}
