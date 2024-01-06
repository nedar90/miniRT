/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:59:29 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 11:29:41 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	keyhook_menu(mlx_key_data_t keydata, t_scene *scene)
{
	static int		flag = 0;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(scene->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		flag = ZOOM;
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		flag = MOVE_Z;
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		flag = MOVE_X;
	if (keydata.key == MLX_KEY_Y && keydata.action == MLX_PRESS)
		flag = MOVE_Y;
	return (flag);
}

void	move(mlx_key_data_t keydata, double *pointer, double step)
{
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
		*pointer -= step;
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		*pointer += step;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;
	int		flag;

	scene = (t_scene *)param;
	flag = keyhook_menu(keydata, scene);
	if (flag == ZOOM && scene->camera.fov <= 175 && scene->camera.fov >= 5)
		move(keydata, &scene->camera.fov, 5);
	if (flag == MOVE_Z && scene->camera.origin.z < DBL_MAX - 1
		&& scene->camera.origin.z > -DBL_MAX + 1)
		move(keydata, &scene->camera.origin.z, 0.9);
	if (flag == MOVE_X && scene->camera.origin.x <= DBL_MAX - 1
		&& scene->camera.origin.x >= -DBL_MAX + 1)
		move(keydata, &scene->camera.origin.x, 0.9);
	if (flag == MOVE_Y && scene->camera.origin.y <= DBL_MAX - 1
		&& scene->camera.origin.y >= 1)
		move(keydata, &scene->camera.origin.y, 0.9);
	render(param);
}
