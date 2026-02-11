/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:28:36 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/10 19:29:26 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "scene.h"

int	is_in_shadow(t_scene *scene, t_ray *l_ray, double dist)
{
	const double	d = trace_ray(scene, l_ray);

	if (d == -1)
		return (0);
	return (d < dist);
}
