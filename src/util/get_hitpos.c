/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hitpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:21:24 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/12 01:44:59 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"

void	get_hitpos(t_ray *ray, double t)
{
	t_vec3	fullray;

	fullray = ray->ray;
	vec3_scale(&fullray, t);
	vec3_add(&ray->startpos, &fullray, &ray->data.hitpos);
}
