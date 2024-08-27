/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 04:06:07 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/11 20:31:49 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_add(t_vec3 *vec1, t_vec3 *vec2, t_vec3 *out)
{
	out->x = vec1->x + vec2->x;
	out->y = vec1->y + vec2->y;
	out->z = vec1->z + vec2->z;
	return (out);
}