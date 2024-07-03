/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:38:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/03 04:41:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

uint32_t	multiply_color(t_color *c1, t_color *c2)
{
	t_color	result;

	result.rgb.r = (c1->rgb.r * c2->rgb.r) / 255;
	result.rgb.g = (c1->rgb.g * c2->rgb.g) / 255;
	result.rgb.b = (c1->rgb.b * c2->rgb.b) / 255;
	return (result.color);
}
