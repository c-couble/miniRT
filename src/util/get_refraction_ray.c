/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refraction_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:20:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/22 09:48:23 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color_util.h"
#include "defines.h"
#include "vec3.h"
#include "util.h"

static double	get_eta(double *dot_e_n, double n0, double n1, t_vec3 *object_n)
{
	double	eta;

	if (*dot_e_n < 0)
		*dot_e_n = *dot_e_n * -1;
	else
	{
		vec3_scale(object_n, -1);
		ft_dswap(&n0, &n1);
	}
	eta = n0 / n1;
	return (eta);
}

void	get_refraction_ray(t_ray *to_ref, t_vec3 *out_ref, double n1)
{
	double	eta;
	double	dot_e_n;
	double	to_sqrt;
	double	res;
	t_vec3	e;
	t_vec3	object_n;

	e = to_ref->ray;
	*out_ref = to_ref->ray;
	object_n = to_ref->data.normal;
	dot_e_n = vec3_dot_product(&e, &object_n);
	eta = get_eta(&dot_e_n, AIR_RATIO, n1, &object_n);
	to_sqrt = 1 - eta * eta * (1 - dot_e_n * dot_e_n);
	if (to_sqrt < 0)
	{
		get_reflection_ray(to_ref, to_ref, out_ref);
		return ;
	}
	res = eta * dot_e_n - sqrt(to_sqrt);
	vec3_scale(&e, eta);
	vec3_scale(&object_n, res);
	vec3_add(&object_n, &e, out_ref);
}
