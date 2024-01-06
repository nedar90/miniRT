/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:54:46 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:19:32 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_menu(t_scene scene)
{
	char	*menu;

	menu = "W: ZOOM";
	mlx_put_string(scene.mlx, menu, 0, 0);
	menu = "X: MOVE_X";
	mlx_put_string(scene.mlx, menu, 10, 25);
	menu = "Y: MOVE_Y";
	mlx_put_string(scene.mlx, menu, 10, 45);
	menu = "Z: MOVE_Z";
	mlx_put_string(scene.mlx, menu, 10, 65);
}
