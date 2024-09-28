/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 02:22:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 04:49:06 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdint.h>
# include "engine.h"
# include "object/mesh.h"
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
void	draw_bvh_at_depth(t_engine *eng, t_bvh_node *bvh, int depth);
void	draw_bvh_from_depth(t_engine *eng, t_bvh_node *bvh, int depth);
void	draw_bounding_box(t_engine *eng, t_bbox *box, uint32_t color);
void	draw_bounding_boxes(t_engine *eng, t_vector *objs, uint32_t color);
void	draw_line(t_engine *eng, t_vec2 *a, t_vec2 *b, uint32_t	color);
void	draw_mesh(t_engine *eng, t_mesh *mesh, uint32_t color);

#endif
