/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_denormalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:31:52 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:32:22 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_math.h"

uint32_t	color_denormalize(t_colorf in)
{
	t_color	tmp;

	tmp.rgb.r = ft_min(in.r * 255.0, 255);
	tmp.rgb.g = ft_min(in.g * 255.0, 255);
	tmp.rgb.b = ft_min(in.b * 255.0, 255);
	return (tmp.color);
}
