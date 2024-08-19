/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_photon.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:47:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/19 11:21:42 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "photon.h"
#include "engine.h"
#include "ray.h"
#include "ft_math.h"

double	get_closest_photon(t_engine *engine, t_ray *ray, t_ray *p_ray)
{
	size_t		i;
	t_photon	*curr;
	t_vec3		d;
	double		tmp;
	double		norm;
		if (ray->data.hitpos.x == 0 &&
		ray->data.hitpos.y == 0 &&
		ray->data.hitpos.z == 0)
			return (MAX_RAY_LEN);
	tmp = MAX_RAY_LEN;
	norm = MAX_RAY_LEN;
	i = 0;
	while (i < engine->photon_map.size)
	{
		curr = at_vector(&engine->photon_map, i);
		vec3_subtract(&curr->pos, &ray->data.hitpos, &d);
		tmp = vec3_get_norm(&d);
		ft_dabs(tmp);
		if (tmp < norm)
		{
			p_ray->ray = curr->pos;
			p_ray->data.color.color = curr->color.color;
			norm = tmp;
		}
		++i;
	}
	return (norm);
}
