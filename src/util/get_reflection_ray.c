/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reflection_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:02:07 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/15 13:21:51 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"

// R = 2(N.L)N - L
t_vec3	get_reflection_ray(t_ray *light_ray, t_ray *camera_ray)
{
	double		dot_nl;
	t_vec3		object_n;
	t_vec3		reflection_ray;

	object_n.x = camera_ray->data.normal.x;
	object_n.y = camera_ray->data.normal.y;
	object_n.z = camera_ray->data.normal.z;
	dot_nl = vec3_dot_product(&object_n, &light_ray->ray) * 2;
	vec3_scale(&object_n, dot_nl);
	vec3_subtract(&object_n, &light_ray->ray, &reflection_ray);
	return (reflection_ray);
}
