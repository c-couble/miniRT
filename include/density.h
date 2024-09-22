/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   density.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:38:03 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 23:23:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DENSITY_H
# define DENSITY_H

#include <sys/types.h>
#include "kdtree.h"

double	*generate_gaussian_arr(size_t size, double mu);
double	density_estimation(t_knn *knn, double bandwidth);

#endif
