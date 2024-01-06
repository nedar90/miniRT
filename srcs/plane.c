/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:10:34 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:28:31 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	normal_at_plane(struct s_objects *obj, t_point object_point)
{
	(void) obj;
	(void) object_point;
	return (new_vector(0, 1, 0));
}

bool	intersection_plane(struct s_objects obj, t_ray *ray)
{
	double	t;

	(void) obj;
	if (fabs(ray->direction.y) < EPSILON)
		return (false);
	t = -ray->origin.y / ray->direction.y;
	if (ray->t < t || t < EPSILON)
		return (false);
	ray->t = t;
	return (true);
}
