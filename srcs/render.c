/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:46:27 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:46:28 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray_to_pixel(t_camera *camera, double x, double y)
{
	double	world_x;
	double	world_y;
	t_point	pixel;
	t_point	origin;
	t_vect	direction;

	world_x = camera->pic_width - (x + 0.5) * camera->pixel;
	world_y = camera->pic_height - (y + 0.5) * camera->pixel;
	pixel = multiply_mx_tp(camera->inverse, new_point(world_x, world_y, -1));
	origin = multiply_mx_tp(camera->inverse, new_point(0, 0, 0));
	direction = normalize(vect_operators(pixel, origin, 0, SUBTRACT));
	return (new_ray(origin, direction));
}

void	render(void *param)
{
	float	x;
	float	y;
	t_scene	*scene;
	t_ray	ray;
	t_color	color;

	y = -1;
	scene = (t_scene *)param;
	init_canvas(&scene->camera);
	while (++y < SCREEN_HIGHT - 1)
	{
		printf("\rRendering: %d%%", (int)(y * 100.0 / SCREEN_HIGHT));
		x = -1;
		while (++x < SCREEN_WIDTH - 1)
		{
			ray = ray_to_pixel(&scene->camera, x, y);
			color = set_color(scene, &ray);
			my_put_pixel(scene->img, x, y, rgb_to_color(color));
		}
	}
}
