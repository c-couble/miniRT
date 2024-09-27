/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:02:40 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 04:56:14 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "texture.h"

typedef struct s_material_data
{
	double		diffuse_ratio;
	double		specular_ratio;
	double		specular_shine;
	double		reflect_ratio;
	double		refraction_ratio;
	t_texture	*texture;
	char		*name;
}	t_material_data;

struct	s_engine;
struct	s_option;

int	parse_material(struct s_engine *engine, struct s_option *data, char *arg);

#endif
