/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_caustic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:10:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 10:33:45 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caustic.h"
#include "kdtree.h"

void	clear_caustic(t_caustic *caustic)
{
	clear_knns(caustic->knn, caustic->knn_nb);
	clear_caustic_maps(&caustic->caustic_maps);
}
