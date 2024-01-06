/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:14:52 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:08:24 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matter	material(void)
{
	t_matter	m;

	m.color = new_color(1.0, 1.0, 1.0);
	m.ambient = new_color(0.1, 0.1, 0.1);
	m.diffusion = 0.9;
	m.specular = 0.9;
	m.shining = 200.0;
	return (m);
}

void	init_transform(t_objects *obj)
{
	obj->transform = identity_mx();
	obj->inverse = identity_mx();
	obj->transpose = identity_mx();
}

void	init_sp(t_objects *obj)
{
	obj->matter = material();
	obj->content->sphere.pos = new_point(0, 0, 0);
	obj->content->sphere.radius = 1.0;
	obj->matter.diffusion = 0.7;
	obj->matter.specular = 0.3;
	obj->interection_obj = intersection_sphere;
	obj->normal_at_obj = normal_at_sphere;
	init_transform(obj);
}

void	init_pl(t_objects *obj)
{
	obj->matter = material();
	obj->content->plane.pos = new_point(0, 0, 0);
	obj->matter.specular = 0.5;
	obj->interection_obj = intersection_plane;
	obj->normal_at_obj = normal_at_plane;
	init_transform(obj);
}

void	init_cy(t_objects *obj)
{
	obj->matter = material();
	obj->content->cylinder.pos = new_point(0, 0, 0);
	obj->content->cylinder.min_height = -INFINITY;
	obj->content->cylinder.max_height = INFINITY;
	obj->content->cylinder.radius = 1.0;
	obj->content->cylinder.is_closed = false;
	obj->interection_obj = intersection_cylinder;
	obj->normal_at_obj = normal_at_cylinder;
	init_transform(obj);
}
