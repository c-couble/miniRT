/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:46:45 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/27 05:43:14 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

# include "engine.h"
# include "object.h"
# include "ray.h"

uint32_t	get_ambiant_light(t_engine *engine);
void		get_fresnel(t_engine *eng, t_ray *c_ray, t_color *color, int depth);
uint32_t	get_light(t_engine *engine, t_ray *ray);
uint32_t	get_pixel_color(t_engine *engine, t_ray *ray, int depth);
void		get_reflection_ray(t_ray *to_ref, t_ray *camera_ray, t_vec3 *out);
uint32_t	get_reflect(t_engine *eng, t_ray *c_ray, t_color color, int depth);
void		get_refraction_ray(t_ray *to_ref, t_vec3 *out_ref, double n1);
uint32_t	get_refract(t_engine *eng, t_ray *c_ray, t_color color, int depth);
void		phong_model(t_object *obj, t_color *l, t_ray *c_ray, t_ray *l_ray);

#endif
