/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_transformation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:34:37 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 10:48:16 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

t_matrix	translate_mx(t_tuple t)
{
	const double	transl[MAX][MAX] = {
	{1, 0, 0, t.x},
	{0, 1, 0, t.y},
	{0, 0, 1, t.z},
	{0, 0, 0, 1},
	};

	return (new_matrix(transl, MAX));
}

t_matrix	scale_mx(double x, double y, double z)
{
	const double	scale[MAX][MAX] = {
	{x, 0, 0, 0},
	{0, y, 0, 0},
	{0, 0, z, 0},
	{0, 0, 0, 1},
	};

	return (new_matrix(scale, MAX));
}

t_matrix	shear_mx(t_shearing x, t_shearing y, t_shearing z)
{
	const double	shear[MAX][MAX] = {
	{1, x.s1, x.s2, 0},
	{y.s1, 1, y.s2, 0},
	{z.s1, z.s2, 1, 0},
	{0, 0, 0, 1},
	};

	return (new_matrix(shear, MAX));
}
