/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:57:42 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:29:35 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	normal_at_sphere(struct s_objects *obj, t_point object_point)
{
	t_vect	object_normal;

	(void)obj;
	object_normal = vect_operators(object_point, \
	new_point(0, 0, 0), 0, SUBTRACT);
	object_normal.w = 0.0;
	return (normalize(object_normal));
}

static int	discriminent_sp(t_tuple abc, t_ray *ray)
{
	double	disc;
	double	time[2];

	disc = (abc.y * abc.y) - (4 * abc.x * abc.z);
	if (disc < 0)
		return (false);
	time[0] = (-abc.y - sqrtf(disc)) / (2 * abc.x);
	time[1] = (-abc.y + sqrtf(disc)) / (2 * abc.x);
	if (ray->t < time[0] && ray->t < time[1])
		return (false);
	if (time[0] <= time[1])
		ray->t = time[0];
	else
		ray->t = time[1];
	return (true);
}

bool	intersection_sphere(struct s_objects obj, t_ray *ray)
{
	t_vect	sp_to_ray;
	t_tuple	abc;

	sp_to_ray = vect_operators(ray->origin, \
	obj.content->sphere.pos, 0, SUBTRACT);
	abc.x = dot(ray->direction, ray->direction);
	abc.y = 2.0 * dot(ray->direction, sp_to_ray);
	abc.z = dot(sp_to_ray, sp_to_ray) - 1.0;
	return (discriminent_sp(abc, ray));
}
