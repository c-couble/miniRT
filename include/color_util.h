/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:29:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/03 05:21:14 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTIL_H
# define COLOR_UTIL_H

#include "color.h"

uint32_t	add_color(t_color *c1, t_color *c2);
uint32_t	multiply_color(t_color *c1, t_color *c2); 
uint32_t	add_scale_color(t_color *c1, t_color *c2, double ratio);
uint32_t	scale_color(t_color *c1, double ratio);

#endif
