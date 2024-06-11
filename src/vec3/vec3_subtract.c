/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_subtract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:25:03 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 20:43:23 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_subtract(t_vec3 *vec1, t_vec3 *vec2, t_vec3 *out)
{
	out->x = vec1->x - vec2->x;
	out->y = vec1->y - vec2->y;
	out->z = vec1->z - vec2->z;
	return (out);
}
