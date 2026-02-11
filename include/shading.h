/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:46:45 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/11 00:33:43 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

# include "ray.h"
# include "scene.h"

t_colorf	get_area_lights(t_scene *scene, t_ray *ray);
void		get_caustics(t_caustic *caustic, t_ray *ray, t_colorf *light);
t_colorf	get_point_lights(t_scene *scene, t_ray *ray);
t_colorf	get_reflect(t_scene *s, t_ray *c_ray, t_colorf color, int depth);
t_colorf	get_fresnel(t_scene *s, t_ray *c_ray, t_colorf color, int depth);
t_colorf	get_refract(t_scene *s, t_ray *c_ray, t_colorf color, int depth);
t_colorf	get_direct_lighting(t_scene *s, t_ray *ray);

void		phong_model(t_light *in, t_colorf *out, t_ray *c_ray, t_ray *l_ray);
t_colorf	shade_ray(t_scene *s, t_ray *c_ray, int depth);

int			is_in_shadow(t_scene *scene, t_ray *l_ray, double dist);
double		create_shadow_ray(t_ray *ray, t_vec3 *light_pos, t_ray *shadow_ray);

#endif
