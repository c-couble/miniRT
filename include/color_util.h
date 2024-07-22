/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:29:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/22 09:49:12 by lespenel         ###   ########.fr       */
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
void		get_reflection_ray(t_ray *to_ref, t_ray *camera_ray, t_vec3 *out);
void		get_refraction_ray(t_ray *to_ref, t_vec3 *out_ref, double n1);
void		phong_model(t_object *obj, t_color *l, t_ray *c_ray, t_ray *l_ray);
uint32_t	get_reflect(t_engine *eng, t_ray *c_ray, t_color color, int depth);
uint32_t	get_refract(t_engine *eng, t_ray *c_ray, t_color color, int depth);
uint32_t	get_normal_color(t_ray *camera_ray);

#endif
