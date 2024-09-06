/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:20:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 04:11:22 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H

# include "color.h"

typedef struct s_ambient_light
{
	double	ratio;
	t_color	color;
}	t_ambient_light;

union	u_object_data;
struct	s_engine;

int	parse_ambient_light(struct s_engine *engine, union u_object_data *data);

#endif
