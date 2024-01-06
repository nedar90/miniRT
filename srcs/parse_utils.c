/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:50:23 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/25 12:11:16 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_tuple(t_tuple *vect, char *str, double min, double max)
{
	char	**tmp;

	comma_handler(str);
	tmp = ft_split(str, ',');
	check_size(tmp, 3);
	if (!is_in_range(&vect->x, ft_atof(tmp[0]), min, max)
		|| !is_in_range(&vect->y, ft_atof(tmp[1]), min, max)
		|| !is_in_range(&vect->z, ft_atof(tmp[2]), min, max))
		ft_error("bad vector range", true);
	ft_free(tmp);
}

void	fill_color(t_color *color, char *str)
{
	char	**tmp;

	comma_handler(str);
	tmp = ft_split(str, ',');
	check_size(tmp, 3);
	if (!is_in_range(&color->r, ft_atof(tmp[0]), 0, 255)
		|| !is_in_range(&color->g, ft_atof(tmp[1]), 0, 255)
		|| !is_in_range(&color->b, ft_atof(tmp[2]), 0, 255))
		ft_error("bad color range", true);
	color->r /= 255;
	color->g /= 255;
	color->b /= 255;
	ft_free(tmp);
}

int	parse_cam(t_scene *scene, char **data)
{
	t_point	origin;
	t_vect	direction;

	if (scene->has_camera)
		ft_error("too many cameras", true);
	direction = new_vector(0, 0, 0);
	check_size(data, 4);
	fill_tuple(&origin, data[1], -DBL_MAX, DBL_MAX);
	scene->camera.origin = new_point(origin.x, origin.y, origin.z);
	fill_tuple(&direction, data[2], -1.0, 1.0);
	scene->camera.direction = new_vector(direction.x, direction.y, direction.z);
	if (!is_normalized(direction))
		ft_error("normalize direction", true);
	if (!is_in_range(&scene->camera.fov, ft_atof(data[3]), 0.0, 180.0))
		ft_error("FOV", true);
	scene->has_camera = true;
	return (0);
}

int	parse_amb(t_scene *scene, char **data)
{
	double	ratio;

	if (scene->has_ambient)
		ft_error("too many ambients", true);
	check_size(data, 3);
	if (!is_in_range(&ratio, ft_atof(data[1]), 0.0, 1.0))
		ft_error("ambient", true);
	fill_color(&scene->ambient, data[2]);
	scene->ambient = color_operators(scene->ambient, \
	(t_color){0}, ratio, MULTI);
	scene->has_ambient = true;
	return (0);
}

int	parse_light(t_scene *scene, char **data)
{
	double	ratio;
	t_tuple	origin;
	t_color	color;
	t_light	*light;

	check_size(data, 4);
	light = malloc(sizeof(t_light));
	if (!light)
		ft_error("malloc light", true);
	fill_tuple(&origin, data[1], -DBL_MAX, DBL_MAX);
	light->pos = new_point(origin.x, origin.y, origin.z);
	if (!is_in_range(&ratio, ft_atof(data[2]), 0.0, 1.0))
		ft_error("light's ratio", true);
	fill_color(&color, data[3]);
	light->inshadow = false;
	light->color = color_operators(color, (t_color){0}, ratio, MULTI);
	light->next = NULL;
	ft_lstadd_light(&scene->light, light);
	return (0);
}
