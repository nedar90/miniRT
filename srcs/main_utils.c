/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:41:23 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/25 11:47:19 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	new_camera(void)
{
	t_camera	camera;

	camera.fov = 0;
	camera.pic_height = 0;
	camera.pic_width = 0;
	camera.pixel = 0;
	camera.inverse = identity_mx();
	camera.transform = identity_mx();
	return (camera);
}

t_scene	create_scene(void)
{
	t_scene	scene;

	scene.has_ambient = false;
	scene.has_camera = false;
	scene.ambient = new_color(0.1, 0.1, 0.1);
	scene.objs = NULL;
	scene.light = NULL;
	scene.camera = new_camera();
	return (scene);
}

void	init_canvas(t_camera *camera)
{
	t_point	up;

	if (camera->direction.x == 0 && camera->direction.y != 0 \
	&& camera->direction.z == 0)
		up = new_vector(0, camera->direction.y, 1e-6);
	else
		up = new_vector(0, 1, 0);
	camera->transform = view_transform(
			new_point(camera->origin.x, camera->origin.y, \
			camera->origin.z),
			up,
			new_vector(camera->direction.x, camera->direction.y, \
			camera->direction.z)
			);
	camera->inverse = inverse_matrix(camera->transform);
	set_camera(camera);
}

void	init(t_scene *scene, char *file_name)
{
	t_objects	*obj;

	obj = scene->objs;
	while (obj)
	{
		obj->matter.ambient = scene->ambient;
		obj = obj->next;
	}
	scene->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HIGHT, file_name, true);
	scene->img = mlx_new_image(scene->mlx, SCREEN_WIDTH, SCREEN_HIGHT);
}

void	check_file_name(char *filename)
{
	int	i;

	i = 0;
	while (filename[i] && filename[i] != '.')
		i++;
	if (ft_strncmp(&filename[i], ".rt", ft_strlen(&filename[i])))
		ft_error("file name", true);
}
