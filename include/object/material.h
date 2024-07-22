/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:02:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/20 03:28:07 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct s_material_data
{
	double	diffuse_ratio;
	double	specular_ratio;
	double	specular_shine;
	double	reflect_ratio;
	double	refraction_ratio;
}	t_material_data;

int	parse_material(t_material_data *material);

#endif