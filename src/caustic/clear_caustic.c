/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_caustic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:10:22 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/27 04:33:18 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caustic.h"
#include "kdtree.h"

void	clear_caustic(t_caustic *caustic)
{
	clear_knn(&caustic->knn);
	clear_caustic_maps(&caustic->caustic_maps);
}
