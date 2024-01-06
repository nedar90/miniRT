/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:28:34 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:09:29 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	orient_xform(t_vect forward, t_vect left, t_vect true_up)
{
	const double	table[MAX][MAX] = {
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1},
	};

	return (new_matrix(table, MAX));
}

t_matrix	view_transform(t_point from, t_point to, t_vect up)
{
	t_point		forward;
	t_point		left;
	t_vect		true_up;
	t_matrix	orientation;

	forward = normalize(vect_operators(to, from, 0, SUBTRACT));
	left = cross(forward, normalize(up));
	true_up = cross(left, forward);
	orientation = orient_xform(forward, left, true_up);
	return (multiply_matrices(
			orientation,
			translate_mx((t_point){-from.x, -from.y, -from.z, 1}))
	);
}

void	set_camera(t_camera *camera)
{
	double	half_view;
	double	aspect;

	half_view = tanf((camera->fov * (M_PI / 180)) / 2.0f);
	aspect = (float)SCREEN_WIDTH / (float)SCREEN_HIGHT;
	if (aspect >= 1)
	{
		camera->pic_width = half_view;
		camera->pic_height = half_view / aspect;
	}
	else
	{
		camera->pic_width = half_view * aspect;
		camera->pic_height = half_view;
	}
	camera->pixel = (camera->pic_width * 2) / (float)SCREEN_WIDTH;
}
