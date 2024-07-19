/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:42:00 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/15 09:43:23 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "vec4.h"

t_vec4	*vec4_create(t_vec3 *vec, double w, t_vec4 *out)
{
	*out = (t_vec4){vec->x, vec->y, vec->z, w};
	return (out);
}
