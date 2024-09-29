/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:02:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 00:03:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "texture.h"

typedef struct s_material_data
{
	double		refract_index;
	double		refract_blend;
	double		diffuse_ratio;
	double		specular_ratio;
	double		specular_shine;
	double		reflect_ratio;
	t_texture	*texture;
	t_texture	*normal_map;
	char		*name;
}	t_material_data;

struct	s_engine;
struct	s_option;

int	parse_material(struct s_engine *engine, struct s_option *data, char *arg);

#endif
