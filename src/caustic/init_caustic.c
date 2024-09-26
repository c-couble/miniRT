/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caustic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 23:06:50 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/26 23:14:47 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caustic.h"
#include "kdtree.h"

int	init_caustic(t_engine *eng, t_caustic *caustic)
{
	caustic->nn = 5;
	caustic->bandwidth = 0.1;
	if (init_knn(&caustic->knn, caustic->nn) == -1)
		return (-1);
	if (init_caustic_maps(eng, caustic) == -1)
		return (-1);
	return (0);
}
