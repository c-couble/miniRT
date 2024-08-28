/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:18:02 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 06:20:19 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONAL_DATA_H
# define OPTIONAL_DATA_H

# include "object/material.h"
# include "texture.h"

typedef enum e_option_t
{
	MATERIAL,
	TEXTURE,
	UNKNOWN_OPTION,
}	t_option_t;

typedef struct s_option
{
	t_material_data	material;
	t_texture		*texture;
	int				has_material;
}	t_option;

struct	s_engine;
struct	s_object;

int	parse_optional_data(struct s_engine *engine, struct s_object *object);

#endif
