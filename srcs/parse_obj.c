/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:49:59 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 10:11:27 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sp(t_scene *scene, char **data)
{
	t_objects	*obj;
	t_matrix	scale;
	t_point		origin;
	double		diameter;

	scale = identity_mx();
	origin = new_point(0, 0, 0);
	check_size(data, 4);
	obj = ft_lstnew();
	obj->content = malloc(sizeof(t_sphere));
	if (!obj->content)
		ft_error("memory allocation", true);
	init_sp(obj);
	fill_tuple(&origin, data[1], -DBL_MAX, DBL_MAX);
	if (!is_in_range(&diameter, ft_atof(data[2]), -DBL_MAX, DBL_MAX))
		ft_error("diameter of sphere", true);
	fill_color(&obj->matter.color, data[3]);
	scale = scale_mx(diameter / 2, diameter / 2, diameter / 2);
	set_transform(obj, \
	translate_mx(new_point(origin.x, origin.y, origin.z)), scale);
	ft_lstadd_front(&scene->objs, obj);
	return (0);
}

t_param	new_param(void)
{
	t_param	param;

	param.diameter = 0;
	param.direction = new_vector(0, 0, 0);
	param.height = INFINITY;
	param.origin = new_point(0, 0, 0);
	return (param);
}

void	fill_cy_attribute(t_objects *obj, t_param param)
{
	t_matrix	scale;
	t_matrix	rotate;
	t_matrix	translate;

	scale = identity_mx();
	translate = identity_mx();
	obj->content->cylinder.is_closed = true;
	obj->content->cylinder.min_height = -param.height / 2.0;
	obj->content->cylinder.max_height = param.height / 2.0;
	obj->content->cylinder.radius = param.diameter / 2.0;
	translate = translate_mx(new_point(param.origin.x, \
	param.origin.y, param.origin.z));
	scale = scale_mx(param.diameter / 2.0, 1, param.diameter / 2.0);
	rotate = rotate_mx(new_vector(param.direction.x, \
	param.direction.y, param.direction.z));
	set_transform(obj, translate, multiply_matrices(rotate, scale));
}

int	parse_cy(t_scene *scene, char **data)
{
	t_objects	*obj;
	t_param		param;

	check_size(data, 6);
	obj = ft_lstnew();
	obj->content = malloc(sizeof(t_cylinder));
	if (!obj->content)
		ft_error("memory allocation", true);
	init_cy(obj);
	param = new_param();
	fill_tuple(&param.origin, data[1], -DBL_MAX, DBL_MAX);
	fill_tuple(&param.direction, data[2], -1.0, 1.0);
	if (!is_normalized(param.direction))
		ft_error("normalize direction", true);
	if (!is_in_range(&param.diameter, ft_atof(data[3]), -DBL_MAX, DBL_MAX))
		ft_error("diameter of cylinder", true);
	if (!is_in_range(&param.height, ft_atof(data[4]), -DBL_MAX, DBL_MAX))
		ft_error("height of cylinder", true);
	fill_color(&obj->matter.color, data[5]);
	fill_cy_attribute(obj, param);
	ft_lstadd_front(&scene->objs, obj);
	return (0);
}

int	parse_pl(t_scene *scene, char **data)
{
	t_objects	*obj;
	t_vect		direction;
	t_point		origin;
	t_matrix	rotate;

	check_size(data, 4);
	obj = ft_lstnew();
	obj->content = malloc(sizeof(t_plane));
	if (!obj->content)
		ft_error("memory allocation", true);
	init_pl(obj);
	fill_tuple(&origin, data[1], -DBL_MAX, DBL_MAX);
	direction = new_vector(0, 0, 0);
	fill_tuple(&direction, data[2], -1.0, 1.0);
	if (!is_normalized(direction))
		ft_error("normalize direction", true);
	fill_color(&obj->matter.color, data[3]);
	rotate = rotate_mx(new_vector(direction.x, direction.y, direction.z));
	set_transform(obj, \
	translate_mx(new_point(origin.x, origin.y, origin.z)), rotate);
	ft_lstadd_front(&scene->objs, obj);
	return (0);
}
