/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fresnel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:31:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/24 01:00:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color_util.h"
#include "defines.h"
#include "shading.h"

static void compute_fresnel(t_ray *ray, double n1, double *kr);

void	get_fresnel(t_engine *eng, t_ray *c_ray, t_color *color, int depth)
{
	double kr;
	t_color refra;
	compute_fresnel(c_ray, c_ray->data.materials.refraction_ratio, &kr);
	refra.color = 0;
	if (kr < 1)
		refra.color = get_refract(eng, c_ray, *color, depth - 1);
	t_color ref;
	ref.color = get_reflect(eng, c_ray, *color, depth - 1);
	ref.color = scale_color(&ref, kr);
	refra.color = scale_color(&refra, 1 - kr);
	color->color = add_color(&refra, &ref);
}

static void	compute_fresnel(t_ray *ray, double n1, double *kr)
{
	double	cosi = vec3_dot_product(&ray->ray, &ray->data.normal);
	double	etai = AIR_RATIO;
	double	etat = n1;
	double	sint = etai / etat * sqrtf(cosi * cosi);
	if (sint >= 1)
		*kr = 1;
	else 
	{
		double cost = sqrtf(1 - sint * sint);
		cosi = fabs(cosi);
		float Rs = ((etat * cosi) - (etai * cost)) 
			/ ((etat * cosi) + (etai * cost));
        float Rp = ((etai * cosi) - (etat * cost))
			/ ((etai * cosi) + (etat * cost));
		*kr = (Rs * Rs + Rp * Rp) / 2;
	}
}
