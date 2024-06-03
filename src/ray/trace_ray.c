/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:00:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/03 12:35:15 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "engine.h"
#include "vector3d.h"
#include "ray.h"
#include "object.h"
#include "math.h"
#include <stdio.h>

static	int sphere(t_object *obj, t_ray *ray);
static	int	cylinder(t_object *obj, t_ray *ray);
static	int	plane(t_object *obj, t_ray *ray);

double	dot_product(t_vector3d a, t_vector3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

static	int	plane(t_object *obj, t_ray *ray)
{
	double dot_ray_n = dot_product(ray->ray, obj->data.plane.orientation);
	if (dot_ray_n == INACCURATE_ZERO)
		return (1);
	double ax = obj->data.plane.orientation.x * obj->data.plane.coordinates.x;
	double by = obj->data.plane.orientation.y * obj->data.plane.coordinates.y;
	double cz = obj->data.plane.orientation.z * obj->data.plane.coordinates.z;
	double d = -(ax + by + cz);

	ax = obj->data.plane.orientation.x * ray->startpos.x;
	by = obj->data.plane.orientation.y * ray->startpos.y;
	cz = obj->data.plane.orientation.z * ray->startpos.z;
	double t = (-(ax + by + cz +d)) / dot_ray_n;
	if (t <= INACCURATE_ZERO || t >= ray->maxlen)
		return (1);
	ray->hitpos.x = ray->startpos.x + ray->ray.x * t;
	ray->hitpos.y = ray->startpos.y + ray->ray.y * t;
	ray->hitpos.z = ray->startpos.z + ray->ray.z * t;
	ray->color = obj->data.plane.color;
	return (0);
}

static	int	cylinder(t_object *obj, t_ray *ray)
{
	(void)obj;
	(void)ray;
	return (1);
}

int	trace_ray(t_engine *engine, t_ray *ray)
{
	size_t		i;
	t_object	*obj;

	i = 0;
	while (i < engine->scene.objects.size)
	{
		obj = at_vector(&engine->scene.objects, i);
		if (obj->type == SPHERE)
		{
			if (sphere(obj, ray) == 0)
				return (0);
		}
		if (obj->type == CYLINDER)
		{
			if (cylinder(obj, ray)== 0)
				return (0);
		}
		if (obj->type == PLANE)
		{
			if (plane(obj, ray) == 0)
				return (0);
		}
		++i;
	}
	return (-1);
}

static	int sphere(t_object *obj, t_ray *ray)
{

	t_vector3d	p;
	p.x = ray->startpos.x - obj->data.sphere.coordinates.x;
	p.y = ray->startpos.y - obj->data.sphere.coordinates.y;
	p.z = ray->startpos.z - obj->data.sphere.coordinates.z;
	double a = powl(ray->ray.x, 2) + powl(ray->ray.y, 2) + powl(ray->ray.z, 2);
	double b = 2 * (p.x * ray->ray.x + p.y * ray->ray.y + p.z * ray->ray.z);
	double c = (powl(p.x, 2) + powl(p.y, 2) + powl(p.z, 2)) - powl(obj->data.sphere.diameter / 2, 2);
	double d = powl(b, 2) - (4 * a * c);
	if (d > 0)
	{
		double r1 = (-b - sqrt(d)) / (2 * a);
		double r2 = (-b + sqrt(d)) / (2 * a);
		double r;
		if (r1 <= INACCURATE_ZERO || r1 > ray->maxlen)
			r = r2;
		else if (r2 <= INACCURATE_ZERO || r2 > ray->maxlen)
			r = r1;
		else
		{
			if (r1 > r2)
				r = r2;
			else
				r = r1;
		}
		if (r <= INACCURATE_ZERO || r > ray->maxlen)
			return (1);
		vector_multiply(&ray->ray, r);
		ray->hitpos = ray->startpos;
		vector_addition(&ray->hitpos, &ray->ray);
		ray->color = obj->data.sphere.color;
		return (0);
	}
	return (1);
}
