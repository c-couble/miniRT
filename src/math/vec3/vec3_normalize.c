/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:05:11 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/12 01:00:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_normalize(t_vec3 *vec)
{
	const double	norm = vec3_get_norm(vec);

	vec3_scale(vec, 1 / norm);
	return (norm);
}
