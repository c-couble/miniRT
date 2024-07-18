/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflection_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:02:07 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/18 15:31:55 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"

// R = 2(N.L)N - L
t_vec3	get_reflection_ray(t_ray *to_ref, t_ray *camera_ray)
{
	double		dot_nl;
	t_vec3		object_n;
	t_vec3		reflection_ray;

	object_n = camera_ray->data.normal;
	dot_nl = vec3_dot_product(&object_n, &to_ref->ray) * 2;
	vec3_scale(&object_n, dot_nl);
	vec3_subtract(&object_n, &to_ref->ray, &reflection_ray);
	vec3_scale(&reflection_ray, -1);
	return (reflection_ray);
}
