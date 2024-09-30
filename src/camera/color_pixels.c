/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 02:53:41 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 17:01:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "color.h"
#include "engine.h"

void	color_pixels(t_engine *engine, size_t i, size_t j, uint32_t c)
{
	if (i < engine->mlx.height && j < engine->mlx.width)
		engine->mlx.addr[(i * engine->mlx.width) + j].color = c;
}
