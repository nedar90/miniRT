/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:33:42 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 08:54:48 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_operators(t_color c1, t_color c2, double scalar, int opt)
{
	if (opt == ADD)
		return ((t_color){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b});
	else if (opt == SUBTRACT)
		return ((t_color){c1.r - c2.r, c1.g - c2.g, c1.b - c2.b});
	else if (opt == MULTI)
		return ((t_color){c1.r * scalar, c1.g * scalar, c1.b * scalar});
	else if (opt == HAMADAR)
		return ((t_color){c1.r * c2.r, c1.g * c2.g, c1.b * c2.b});
	else
		return ((t_color){0});
}

t_color	calculate_color(t_scene *scene, t_ray *ray, t_light *light, \
t_objects *obj)
{
	t_comput	e;
	t_color		color;

	e.hit_point = position(*ray);
	e.normal = normal_at(*obj, e.hit_point);
	e.eye = vect_operators(ray->direction, (t_tuple){0}, 0, NEGATE);
	if (dot(e.normal, e.eye) < 0)
		e.normal = vect_operators(e.normal, (t_tuple){0}, 0, NEGATE);
	light->inshadow = is_inshadow(*scene, e.hit_point, e.normal, *light);
	color = lighting(obj->matter, *light, e);
	return (color);
}

t_color	set_color(t_scene *scene, t_ray *ray)
{
	t_color		color;
	t_light		*light;
	t_objects	*obj;

	obj = scene->objs;
	color = scene->ambient;
	while (obj)
	{
		light = scene->light;
		if (intersection(*obj, ray))
		{
			color = new_color(0, 0, 0);
			while (light)
			{
				color = color_operators(color,
						calculate_color(scene, ray, light, obj),
						0, ADD);
				light = light->next;
			}
		}
		obj = obj->next;
	}
	return (color);
}

static int	convert(float color)
{
	if (color > 1)
		color = 1;
	color *= 255 + 0.5;
	return (color);
}

int	rgb_to_color(t_color color)
{
	return (
		convert(color.r) << 24
		| convert(color.g) << 16
		| convert(color.b) << 8
		| 0xff);
}
