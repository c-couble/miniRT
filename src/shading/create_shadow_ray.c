/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shadow_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:27:50 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/10 19:28:10 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

double	create_shadow_ray(t_ray *ray, t_vec3 *light_pos, t_ray *shadow_ray)
{
	double	dist;

	shadow_ray->startpos = ray->data.hitpos;
	vec3_subtract(light_pos, &shadow_ray->startpos, &shadow_ray->ray);
	dist = vec3_normalize(&shadow_ray->ray);
	get_inv_dir(shadow_ray);
	return (dist);
}
