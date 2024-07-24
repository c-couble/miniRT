/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_refraction_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 00:20:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/24 01:18:06 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "defines.h"
#include "shading.h"
#include "util.h"

#include <stdio.h>
void	get_refraction_ray(t_ray *to_ref, t_vec3 *out_ref, double n1)
{
	t_vec3	n;
	t_vec3	i;
	double	k;
	double	dot_n_i;
	double	etai;
	double	etat;
	double	eta;

	i = to_ref->ray;
	n = to_ref->data.normal;
	etai = AIR_RATIO;
	etat = n1;
	dot_n_i = vec3_dot_product(&n, &i);
	if (dot_n_i < 0)
		dot_n_i = -dot_n_i;
	else
	{
		n.x = -n.x;
		n.y = -n.y;
		n.z = -n.z;
		ft_dswap(&etai, &etat);
	}
	eta = etai / etat;
	k = 1 - eta * eta * (1 - dot_n_i * dot_n_i);
	if (k < 0)
	{
		return ;
	}
	vec3_scale(&i, eta);
	vec3_scale(&n, eta * dot_n_i - sqrtf(k));
	vec3_add(&n, &i, out_ref);

}
