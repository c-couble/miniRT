/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:20:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/14 08:20:32 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H

# include "object/rgb.h"

typedef struct s_ambient_light
{
	double	ratio;
	t_rgb	color;
}	t_ambient_light;

union	u_object_data;

int	parse_ambient_light(union u_object_data *data);

#endif
