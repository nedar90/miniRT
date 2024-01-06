/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:34:12 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:21:18 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_rotation_angles(t_vect vec, double *x, double *z)
{
	double	ratio;

	ratio = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	if (0.0 == ratio)
		*z = M_PI_2;
	else
		*z = acos(vec.y / ratio);
	*x = acos(ratio);
}

t_matrix	rotate_x(double rad)
{
	const double	sine = sin(rad);
	const double	cosine = cos(rad);
	const double	rotate[MAX][MAX] = {
	{1, 0, 0, 0},
	{0, cosine, -sine, 0},
	{0, sine, cosine, 0},
	{0, 0, 0, 1},
	};

	return (new_matrix(rotate, MAX));
}

t_matrix	rotate_y(double rad)
{
	const double	sine = sin(rad);
	const double	cosine = cos(rad);
	const double	rotate[MAX][MAX] = {
	{cosine, 0, sine, 0},
	{0, 1, 0, 0},
	{-sine, 0, cosine, 0},
	{0, 0, 0, 1},
	};

	return (new_matrix(rotate, MAX));
}

t_matrix	rotate_z(double rad)
{
	const double	sine = sin(rad);
	const double	cosine = cos(rad);
	const double	rotate[MAX][MAX] = {
	{cosine, -sine, 0, 0},
	{sine, cosine, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	};

	return (new_matrix(rotate, MAX));
}

t_matrix	rotate_mx(t_vect vector)
{
	double		x_angle;
	double		z_angle;
	t_matrix	rot_z;
	t_matrix	rot_x;
	t_matrix	full_rot;

	get_rotation_angles(vector, &x_angle, &z_angle);
	rot_z = rotate_z(z_angle);
	rot_x = rotate_x(x_angle);
	full_rot = multiply_matrices(rot_z, rot_x);
	return (full_rot);
}
