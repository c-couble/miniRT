/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 05:52:25 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 03:30:48 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "color.h"
#include "texture.h"

t_colorf	get_texture_color(t_texture *texture, double u, double v)
{
	t_colorf	color;
	int			col;
	int			line;

	color.r = 1;
	color.g = 1;
	color.b = 1;
	if (u < 0 || u > 1 || v < 0 || v > 1)
		return (color);
	col = u * texture->width;
	line = v * texture->height;
	return (texture->texture[line * texture->width + col]);
}
