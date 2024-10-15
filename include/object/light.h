/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:30:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/02 01:54:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "vec3.h"

typedef struct s_light
{
	t_vec3	pos;
	double	ratio;
	t_color	color;
}	t_light;

struct	s_engine;
union	u_object_data;

int	parse_light(struct s_engine *engine, union u_object_data *object);

#endif
