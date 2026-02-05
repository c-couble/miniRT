/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:46:45 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 00:28:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

# include "scene.h"
# include "object/light.h"
# include "ray.h"
# include "vec3.h"

// TODO clean
t_colorf	get_ambiant_light(t_scene *scene);
uint32_t	get_color(t_scene *scene, t_ray *c_ray, int depth);
void		get_caustics(t_caustic *caustic, t_ray *ray, t_color *light);
t_colorf	get_reflect(t_scene *scene, t_ray *c_ray, t_colorf color, int depth);
t_colorf	get_fresnel(t_scene *scene, t_ray *c_ray, t_colorf color, int depth);
t_colorf	get_pixel_color(t_scene *scene, t_ray *c_ray, int depth);

t_colorf	get_refract(t_scene *scene, t_ray *c_ray, t_colorf color, int depth);
// void		get_fresnel(t_scene *scene, t_ray *cray, t_vec3 *color, int depth);
t_colorf	get_light(t_scene *scene, t_ray *ray);
// t_vec3		get_pixel_color(t_scene *scene, t_ray *ray, int depth);
void		get_reflection_ray(t_ray *to_ref, t_ray *camera_ray, t_vec3 *out);
// uint32_t	get_reflect(t_scene *scene, t_ray *c_ray, t_color color, int depth);

// t_vec3		get_reflect(t_scene *scene, t_ray *c_ray, t_vec3 color, int depth);
void		get_refraction_ray(t_ray *to_ref, t_vec3 *out_ref, double n1);

void		phong_model(t_light *in, t_colorf *out, t_ray *c_ray, t_ray *l_ray);

#endif
