/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:34:15 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:57:26 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	normal_at_cylinder(struct s_objects *obj, t_point object_point)
{
	double		dist;
	t_cylinder	cy;

	(void)obj;
	cy = obj->content->cylinder;
	dist = powf(object_point.x, 2) + powf(object_point.z, 2);
	if (dist < 1.0 && object_point.y >= (cy.max_height - EPSILON))
		return (new_vector(0, 1, 0));
	if (dist < 1.0 && object_point.y <= (cy.min_height + EPSILON))
		return (new_vector(0, -1, 0));
	return (new_vector(object_point.x, 0.0, object_point.z));
}

static bool	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return ((powf(x, 2) + powf(z, 2)) <= 1.0);
}

void	intersect_caps(t_objects obj, t_ray *ray, double time[4])
{
	double	t;

	if (!obj.content->cylinder.is_closed
		|| fabs(ray->direction.y) < EPSILON)
		return ;
	t = (obj.content->cylinder.min_height - ray->origin.y) / ray->direction.y;
	if (check_cap(*ray, t))
		time[0] = t;
	t = (obj.content->cylinder.max_height - ray->origin.y) / ray->direction.y;
	if (check_cap(*ray, t) && ray->t > t)
		time[1] = t;
}

bool	check_time_interval(t_objects obj, t_ray *ray, double t)
{
	double	y;

	y = ray->origin.y + (t * ray->direction.y);
	if (obj.content->cylinder.min_height < y 
		&& obj.content->cylinder.max_height > y)
		return (true);
	return (false);
}

double	ft_min(double *num)
{
	double	min;
	int		i;

	min = *num;
	i = 0;
	while (++i < 4)
	{
		if (num[i] < min)
			min = num[i];
	}
	return (min);
}
