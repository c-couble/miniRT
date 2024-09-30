/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:52:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 07:01:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "object/material.h"

void	init_material(t_material_data *data)
{
	data->diffuse_ratio = DIFFUSE_RATIO;
	data->specular_ratio = SPECULAR_RATIO;
	data->specular_shine = SPECULAR_SHINE;
	data->reflect_ratio = REFLECT_RATIO;
	data->refract_index = 0;
	data->refract_blend = 1;
	data->texture = NULL;
	data->normal_map = NULL;
	data->name = NULL;
}
