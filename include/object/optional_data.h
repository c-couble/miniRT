/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:18:02 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/15 10:04:08 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONAL_DATA_H
# define OPTIONAL_DATA_H

# include "object/material.h"
# include "texture.h"
# include "checkerboard.h"

typedef enum e_option_t
{
	MATERIAL,
	TEXTURE,
	NORMAL_MAP,
	CHECKERBOARD,
	CAUSTIC,
	SAVE_RENDER,
	BACKGROUND_COLOR,
	NO_SHADOW,
	UNKNOWN_OPTION,
}	t_option_t;

typedef struct s_option
{
	t_checkerboard	checker;
	t_material_data	material;
	t_texture		*down_texture;
	t_texture		*texture;
	t_texture		*up_texture;
	int				photon_nb;
	t_texture		*normal_map;
	t_texture		*up_normal_map;
	t_texture		*down_normal_map;
	int				has_shadow;
}	t_option;

struct	s_engine;
struct	s_object;

int	parse_optional_data(struct s_engine *engine, struct s_object *object);
int	parse_background_color(struct s_engine *engine, t_option *data, char *arg);
int	parse_no_shadow(struct s_engine *engine, t_option *data, char *arg);

#endif
