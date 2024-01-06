/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:34:15 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 16:53:03 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	discriminent_cy(t_objects obj, t_tuple abc, t_ray *ray, \
double time[4])
{
	double	disc;
	double	t;
	double	min;

	disc = powf(abc.y, 2) - (4.0 * abc.x * abc.z);
	if (disc < 0.0)
		return (false);
	t = (-abc.y - sqrtf(disc)) / (2 * abc.x);
	if (check_time_interval(obj, ray, t))
		time[2] = t;
	t = (-abc.y + sqrtf(disc)) / (2 * abc.x);
	if (check_time_interval(obj, ray, t))
		time[3] = t;
	min = ft_min(time);
	if (min > ray->t)
		return (false);
	else
		ray->t = min;
	return (true);
}

bool	intersection_cylinder(struct s_objects obj, t_ray *ray)
{
	t_tuple	abc;
	double	time[4];

	time[0] = INFINITY;
	time[1] = INFINITY;
	time[2] = INFINITY;
	time[3] = INFINITY;
	intersect_caps(obj, ray, &time[0]);
	abc.x = powf(ray->direction.x, 2) + powf(ray->direction.z, 2);
	if (fabs(abc.x) < EPSILON)
		return (false);
	abc.y = (2.0 * ray->origin.x * ray->direction.x)
		+ (2.0 * ray->origin.z * ray->direction.z);
	abc.z = powf(ray->origin.x, 2) + powf(ray->origin.z, 2) - 1.0;
	return (discriminent_cy(obj, abc, ray, time));
}
