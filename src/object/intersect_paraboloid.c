/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:00:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/03 03:32:48 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include "vec3.h"
#include "ray.h"
#include "math_util.h"
#include "object.h"
#include "util.h"

void	get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid);
int		check_height(t_ray *ray, t_paraboloid *para);

double	solve_paraboloid_equation(t_vec3 *origin, t_vec3 *dir, t_ray *ray, t_object *obj)
{
	t_quadratic	q;
	double		t;
	double		a;

	a = obj->data.paraboloid.ray_coef;
	q.a = a * (dir->x * dir->x + dir->y * dir->y);
	q.b = a * 2 * (origin->x * dir->x + origin->y * dir->y) - dir->z;
	q.c = a * (origin->x * origin->x + origin->y * origin->y) - origin->z;
	solve_quadratic_equation(&q);
	if (q.delta < 0)
		return (-1);
	t = get_closest_distance(q.r1, q.r2);
	get_hitpos(ray, t);
	if (check_height(ray, &obj->data.paraboloid))
	{
		t = get_bigest_distance(q.r1, q.r2);
		get_hitpos(ray, t);
		if (check_height(ray, &obj->data.paraboloid))
			return (-1);
	}
	get_paraboloid_normal(ray, &obj->data.paraboloid);
	ray->data.color = obj->data.paraboloid.color;
	return (t);
}

double	intersect_paraboloid(t_object *obj, t_ray *ray)
{
	const t_paraboloid	para = obj->data.paraboloid;
	t_ray				offset_ray;

	vec3_subtract(&ray->startpos, (t_vec3 *)&para.pos, &offset_ray.startpos);
	quaternion_rotate(&offset_ray.startpos, 
				   (t_vec3 *)&para.rot_axis, para.theta, &offset_ray.startpos);
	quaternion_rotate(&ray->ray, (t_vec3 *)&para.rot_axis, 
				   para.theta, &offset_ray.ray);
	return (solve_paraboloid_equation(&offset_ray.startpos, &offset_ray.ray, ray, obj));
}

void	get_paraboloid_normal(t_ray *ray, t_paraboloid *paraboloid)
{
	ray->data.normal.x = -2 * paraboloid->ray_coef 
		* (paraboloid->pos.x - ray->data.hitpos.x);
	ray->data.normal.y = -2 * paraboloid->ray_coef 
		* (paraboloid->pos.y - ray->data.hitpos.y);
	ray->data.normal.z = -1;
	vec3_normalize(&ray->data.normal);
}

int	check_height(t_ray *ray, t_paraboloid *para)
{
	t_vec3		origin_hit;

	vec3_subtract(&ray->data.hitpos, &para->pos, &origin_hit);
	if (vec3_dot_product(&para->axis, &origin_hit) > para->height)
		return (-1);
	return (0);
}
