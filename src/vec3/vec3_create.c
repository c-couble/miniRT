/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:27:54 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/24 07:28:22 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_create(double x, double y, double z, t_vec3 *out)
{
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}
