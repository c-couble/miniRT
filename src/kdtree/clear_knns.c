/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_knns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:22:30 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 10:38:08 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "kdtree.h"

static void	clear_knn(t_knn *knn);

void	clear_knns(t_knn *knn, size_t knn_size)
{
	size_t	i;

	i = 0;
	while (i < knn_size && knn[i].querys)
	{
		clear_knn(&knn[i]);
		++i;
	}
	free(knn);
}

static void	clear_knn(t_knn *knn)
{
	free(knn->querys);
}
