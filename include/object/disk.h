/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:44:08 by lespenel          #+#    #+#             */
/*   Updated: 2025/07/06 23:08:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H

# include "color.h"
# include "vec3.h"

typedef struct s_disk
{
	t_vec3			pos;
	t_vec3			normal;
	double			diameter;
	double			radius;
	double			radiussq;
	t_color			color;
    double          theta;
    t_vec3          rot_axis;
}	t_disk;

struct	s_engine;
union	u_object_data;

int	parse_disk(struct s_engine *engine, union u_object_data *object);

#endif
