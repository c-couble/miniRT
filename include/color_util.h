/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:29:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 10:47:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTIL_H
# define COLOR_UTIL_H

# include "color.h"
# include "ray.h"

uint32_t	add_color(t_color *c1, t_color *c2);
uint32_t	multiply_color(t_color *c1, t_color *c2);
uint32_t	add_scale_color(t_color *c1, t_color *c2, double ratio);
uint32_t	scale_color(t_color *c1, double ratio);
uint32_t	get_normal_color(t_ray *camera_ray);
uint32_t	get_uv_color(t_ray *camera_ray);
uint32_t	get_interpolate_color(uint32_t a, uint32_t b, int curr, int max);

#endif
