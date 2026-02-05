/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:46:45 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:22:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADING_H
# define SHADING_H

# include "scene.h"
# include "ray.h"

uint32_t	get_color(t_scene *scene, t_ray *c_ray, int depth);
void		get_caustics(t_caustic *caustic, t_ray *ray, t_colorf *light);
t_colorf	get_reflect(t_scene *s, t_ray *c_ray, t_colorf color, int depth);
t_colorf	get_fresnel(t_scene *s, t_ray *c_ray, t_colorf color, int depth);
t_colorf	get_pixel_color(t_scene *s, t_ray *c_ray, int depth);

t_colorf	get_refract(t_scene *s, t_ray *c_ray, t_colorf color, int depth);
t_colorf	get_light(t_scene *s, t_ray *ray);

void		phong_model(t_light *in, t_colorf *out, t_ray *c_ray, t_ray *l_ray);

#endif
