/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_photon_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:03:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/18 16:04:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "object.h"
#include "photon.h"
#include "util.h"
#include "vec3.h"
#include "vector.h"
#include <stdio.h>

void	print_photon_map(t_engine *engine)
{
	size_t		i;
	t_photon	*curr;
	
	i = 0;
	while (i < engine->photon_map.size)
	{
		curr = at_vector(&engine->photon_map, i);
		print_vec3(&curr->pos, "p_ray");
		printf("color r = %d, g = %d, b = %d\n", curr->color.rgb.r, curr->color.rgb.b,
		 curr->color.rgb.b);
		++i;
	}

}
int	get_photon(t_engine *eng, t_light *light)
{
	size_t		i;
	t_object	*curr;
	t_photon	photon;
	t_ray		p_ray;

	i = 0;
	photon.color.color = 15510;
	while (i < eng->scene.objects.size)
	{
		curr = at_vector(&eng->scene.objects, i);
		if (curr->type == SPHERE && curr->material.reflect_ratio)
		{
			p_ray.startpos = light->pos;
			vec3_subtract(&curr->data.sphere.pos, &p_ray.startpos, &p_ray.ray);
			vec3_normalize(&p_ray.ray);
			if (trace_photon(eng, &p_ray, DEPTH))
			{
				photon.pos = p_ray.data.hitpos;
				dprintf(2, "Added photon, obj type == %d\n", curr->type);
				(void)light;
				if (add_vector(&eng->photon_map, &photon, 1) == -1)
					return (-1);
			}
		}
		++i;
	}
	(void)eng;
	(void)light;
	return (0);
}

int	init_photon_map(t_engine *eng)
{
	size_t		i;
	t_object	*curr;

	dprintf(2, "Init photon map\n");
	init_vector(&eng->photon_map, sizeof(t_photon));
	i = 0;
	while (i < eng->scene.objects.size)
	{
		curr = at_vector(&eng->scene.objects, i);
		if (curr->type == LIGHT)
		{
			if (get_photon(eng, (t_light *)&curr->data.light) == -1)
			{
				dprintf(2, "Bad alloc init photon\n");
				return (-1);
			}
			dprintf(2, "Light\n");
		}
		++i;
	}
	print_photon_map(eng);
	return (0);
}
