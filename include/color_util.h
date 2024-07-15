/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:29:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/16 00:06:08 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTIL_H
# define COLOR_UTIL_H

# include "color.h"
# include "object.h"

uint32_t	add_color(t_color *c1, t_color *c2);
uint32_t	multiply_color(t_color *c1, t_color *c2);
uint32_t	add_scale_color(t_color *c1, t_color *c2, double ratio);
uint32_t	scale_color(t_color *c1, double ratio);
t_vec3		get_reflection_ray(t_ray *light_ray, t_ray *camera_ray);
void		phong_model(t_object *obj, t_color *l, t_ray *c_ray, t_ray *l_ray);
void		get_reflect(t_engine *eng, t_ray *c_ray, t_ray *to_ref, int depth);

#endif
