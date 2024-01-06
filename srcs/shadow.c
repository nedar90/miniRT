/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:26:48 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:44:47 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_inshadow(t_scene scene, t_point point, t_vect normal, t_light light)
{
	t_tuple		v;
	t_ray		r;
	t_objects	*obj;
	t_tuple		t;
	t_tuple		over_point;

	t = vect_operators(normal, (t_vect){0}, 0.001, MULTI);
	over_point = vect_operators(point, t, 0, ADD);
	v = vect_operators(light.pos, over_point, 0, SUBTRACT);
	r = new_ray(over_point, normalize(v));
	obj = scene.objs;
	while (obj)
	{
		if (intersection(*obj, &r) && r.t < magnitude(v) && r.t > 0.001)
			return (TRUE);
		obj = obj->next;
	}
	return (FALSE);
}
