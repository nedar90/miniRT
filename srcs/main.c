/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:41:23 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/25 11:52:23 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
//fix memory leak when there is an error in parser

int	main(int ac, char **av)
{
	t_scene	scene;

	if (ac != 2)
		ft_error("arguments\n", true);
	check_file_name(av[1]);
	scene = create_scene();
	parser(&scene, av[1]);
	init(&scene, av[1]);
	print_menu(scene);
	mlx_image_to_window(scene.mlx, scene.img, 0, 0);
	mlx_key_hook(scene.mlx, &keyhook, &scene);
	mlx_loop_hook(scene.mlx, render, &scene);
	mlx_loop(scene.mlx);
	mlx_terminate(scene.mlx);
	free_scene(&scene);
	return (0);
}
