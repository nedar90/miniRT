/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:28:42 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 09:14:14 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_objects *obj, t_matrix translate, t_matrix scale)
{
	obj->transform = multiply_matrices(translate, scale);
	obj->inverse = inverse_matrix(obj->transform);
	obj->transpose = transpose_mx(obj->inverse);
}

t_vect	normal_at(t_objects obj, t_point world_point)
{
	t_point	object_point;
	t_vect	object_normal;
	t_vect	world_normal;

	object_point = multiply_mx_tp(obj.inverse, world_point);
	object_normal = obj.normal_at_obj(&obj, object_point);
	world_normal = multiply_mx_tp(obj.transpose, object_normal);
	world_normal.w = 0.0;
	return (normalize(world_normal));
}

int	intersection(t_objects objs, t_ray *ray)
{
	t_ray	l_ray;

	l_ray = transform(*ray, objs.inverse);
	l_ray.t = ray->t;
	if (!objs.interection_obj(objs, &l_ray) \
	|| l_ray.t == INFINITY || l_ray.t < 0.001)
		return (0);
	ray->t = l_ray.t;
	return (1);
}
