/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 06:55:42 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 08:51:10 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERBOARD_H
# define CHECKERBOARD_H

# include "color.h"
# include "ray.h"

typedef struct s_checkerboard
{
	int		x_size;
	int		y_size;
	t_color	x_color;
	t_color	y_color;
}	t_checkerboard;

struct	s_engine;
struct	s_option;
struct	s_object;

void	apply_checkerboard(t_ray *ray, struct s_object *obj);
int		parse_checkerboard(struct s_engine *e, struct s_option *o, char *args);

#endif
