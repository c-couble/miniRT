/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:30:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 17:32:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector3d.h"
# include "object/rgb.h"

typedef struct s_light
{
	t_vector3d	coordinates;
	double		ratio;
	t_rgb		color;
}	t_light;

union	u_object_data;

int	parse_light(union u_object_data *object);

#endif
