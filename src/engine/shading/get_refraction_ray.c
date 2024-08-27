/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refraction_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:20:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/27 01:15:16 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "defines.h"
#include "shading.h"
#include "util.h"

static	double	get_eta(double *dot_ni, double n1, t_vec3 *n)
{
	double	etai;
	double	etat;

	etai = AIR_RATIO;
	etat = n1;
	if (*dot_ni < 0)
		*dot_ni = -*dot_ni;
	else
	{
		n->x = -n->x;
		n->y = -n->y;
		n->z = -n->z;
		ft_dswap(&etai, &etat);
	}
	return (etai / etat);
}

void	get_refraction_ray(t_ray *to_ref, t_vec3 *out_ref, double n1)
{
	t_vec3	n;
	t_vec3	i;
	double	k;
	double	dot_n_i;
	double	eta;

	i = to_ref->ray;
	n = to_ref->data.raw_normal;
	dot_n_i = vec3_dot(&n, &i);
	eta = get_eta(&dot_n_i, n1, &n);
	k = 1 - eta * eta * (1 - dot_n_i * dot_n_i);
	if (k < 0)
	{
		get_reflection_ray(to_ref, to_ref, out_ref);
		return ;
	}
	vec3_scale(&i, eta);
	vec3_scale(&n, eta * dot_n_i - sqrtf(k));
	vec3_add(&n, &i, out_ref);
}
