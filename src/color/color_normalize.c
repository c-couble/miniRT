/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 00:48:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_colorf	color_normalize(t_color in)
{
	t_colorf	out;

	out.r = in.rgb.r / 255.0;
	out.g = in.rgb.g / 255.0;
	out.b = in.rgb.b / 255.0;
	return (out);
}
