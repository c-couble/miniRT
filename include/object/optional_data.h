/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:18:02 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:20:35 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONAL_DATA_H
# define OPTIONAL_DATA_H

# include "object/material.h"

typedef enum e_option_t
{
	MATERIAL,
	UNKNOWN_OPTION,
}	t_option_t;

typedef struct s_optional_data
{
	t_material_data	material;
	int				has_material;
}	t_optional_data;

struct	s_object;

int	parse_optional_data(struct s_object *object);

#endif
