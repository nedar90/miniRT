/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:07:26 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:28:38 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	new_ray(t_vect origin, t_vect direction)
{
	return ((t_ray){
		origin,
		direction,
		INFINITY
	});
}

t_point	position(t_ray ray)
{
	t_tuple	v;

	v = vect_operators(ray.direction, (t_tuple){0}, ray.t, MULTI);
	v = vect_operators(ray.origin, v, 0, ADD);
	return (v);
}

t_ray	transform(t_ray r, t_matrix m)
{
	return (
		new_ray(
			multiply_mx_tp(m, r.origin),
			multiply_mx_tp(m, r.direction))
	);
}
