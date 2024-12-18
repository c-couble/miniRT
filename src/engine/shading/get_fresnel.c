/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fresnel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:31:00 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/30 20:40:35 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "defines.h"
#include "shading.h"

static void		compute_fresnel(t_ray *ray, double n1, double *kr);
static double	compute_kr(double cosi, double etai, double etat, double sint);

void	get_fresnel(t_scene *scene, t_ray *c_ray, t_color *color, int depth)
{
	double	kr;
	t_color	refract;
	t_color	reflect;

	compute_fresnel(c_ray, c_ray->data.materials->refract_index, &kr);
	refract.color = 0;
	if (kr < 1)
		refract.color = get_refract(scene, c_ray, *color, depth - 1);
	reflect.color = get_reflect(scene, c_ray, *color, depth - 1);
	reflect.color = scale_color(&reflect, kr);
	refract.color = scale_color(&refract, 1 - kr);
	color->color = add_color(&refract, &reflect);
}

static void	compute_fresnel(t_ray *ray, double n1, double *kr)
{
	double	cosi;
	double	etai;
	double	etat;
	double	sint;

	cosi = vec3_dot(&ray->ray, &ray->data.normal);
	etai = AIR_RATIO;
	etat = n1;
	sint = etai / etat * sqrt(cosi * cosi);
	if (sint >= 1)
		*kr = 1;
	else
	{
		cosi = fabs(cosi);
		*kr = compute_kr(cosi, etai, etat, sint);
	}
}

static	double	compute_kr(double cosi, double etai, double etat, double sint)
{
	const double	cost = sqrt(1 - sint * sint);
	const double	rs = ((etat * cosi) - (etai * cost))
		/ ((etat * cosi) + (etai * cost));
	const double	rp = ((etai * cosi) - (etat * cost))
		/ ((etai * cosi) + (etat * cost));

	return ((rs * rs + rp * rp) / 2);
}
