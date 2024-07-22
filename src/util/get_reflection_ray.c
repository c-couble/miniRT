/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflection_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:02:07 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/22 05:51:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"

// R = I - 2(N.I)N
void	get_reflection_ray(t_ray *to_ref, t_ray *camera_ray, t_vec3 *out)
{
	double		dot_nl;
	t_vec3		normal;

	normal = camera_ray->data.normal;
	dot_nl = vec3_dot_product(&normal, &to_ref->ray) * 2;
	vec3_scale(&normal, dot_nl);
	vec3_subtract(&to_ref->ray, &normal, out);
}
