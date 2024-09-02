/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:52:13 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 04:56:22 by ccouble          ###   ########.fr       */
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
	data->refraction_ratio = 0;
	data->texture = NULL;
	data->name = NULL;
}
