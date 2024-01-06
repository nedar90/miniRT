/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:58:40 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:44:24 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

t_tuple	vect_operators(t_tuple a, t_tuple b, double scalar, int opt)
{
	if (opt == ADD)
		return ((t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
	else if (opt == SUBTRACT)
		return ((t_tuple){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w});
	else if (opt == MULTI)
		return ((t_tuple){a.x * scalar, a.y * scalar, \
		a.z * scalar, a.w * scalar});
	else if (opt == NEGATE)
		return ((t_tuple){-a.x, -a.y, -a.z, a.w});
	else if (opt == DIVISION)
		return ((t_tuple){a.x / scalar, a.y / scalar, \
		a.z / scalar, a.w / scalar});
	else
		return ((t_tuple){0});
}

double	magnitude(t_tuple v)
{
	return (
		sqrtf(v.x * v.x
			+ v.y * v.y
			+ v.z * v.z
			+ v.w * v.w)
	);
}

t_tuple	normalize(t_tuple v)
{
	double	len;

	len = magnitude(v);
	return ((t_tuple){
		v.x / len,
		v.y / len,
		v.z / len,
		v.w / len});
}

double	dot(t_tuple v1, t_tuple v2)
{
	return (
		v1.x * v2.x
		+ v1.y * v2.y
		+ v1.z * v2.z
		+ v1.w * v2.w
	);
}

t_tuple	cross(t_tuple v1, t_tuple v2)
{
	return (new_vector(v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x));
}
