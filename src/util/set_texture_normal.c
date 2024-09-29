/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 09:31:36 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/29 09:37:04 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

void	set_texture_normal(t_object *obj, t_ray *ray, int face)
{
	if (face == 0)
	{
		ray->data.texture = obj->optional_data.texture;
		ray->data.normal_map = obj->optional_data.normal_map;
		return ;
	}
	if (face == 1)
	{
		ray->data.texture = obj->optional_data.up_texture;
		ray->data.normal_map = obj->optional_data.up_normal_map;
		return ;
	}
	ray->data.texture = obj->optional_data.down_texture;
	ray->data.normal_map = obj->optional_data.down_normal_map;
}
