/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:22:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/21 22:15:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdint.h>
# include "engine.h"
# include "vec2.h"

typedef struct s_line
{
	t_vec2		*a;
	t_vec2		*b;
	int			dx;
	int			dy;
	uint32_t	color;
}	t_line;

void	draw_bvh(t_engine *engine);
void	draw_line(t_engine *eng, t_vec2 *a, t_vec2 *b, uint32_t	color);
void	draw_bounding_box(t_engine *eng, t_bbox *box, uint32_t color);
void	draw_bounding_boxes(t_engine *eng, t_vector *objs, uint32_t color);
void	draw_square(t_engine *eng, int size, t_vec2 *p, uint32_t color);
void	draw_graph(t_engine * eng, size_t size, double *data);

#endif
