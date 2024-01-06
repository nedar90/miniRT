/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:08:38 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 08:53:36 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	specular(t_matter m, t_light light, \
double light_dot_normal, double reflect_dot_eye)
{
	if (light_dot_normal < 0 || reflect_dot_eye <= 0 || light.inshadow == true)
		return (new_color(0, 0, 0));
	else
		return (
			color_operators(
				light.color,
				(t_color){0},
			m.specular * powf(reflect_dot_eye, m.shining),
			MULTI)
		);
}

static t_color	diffuse(t_matter m, double \
light_dot_normal, t_color effective, t_light light)
{
	if (light_dot_normal < 0 || light.inshadow == true)
		return (new_color(0, 0, 0));
	else
		return (
			color_operators(
				effective,
				(t_color){0},
			m.diffusion * light_dot_normal,
			MULTI)
		);
}

t_color	lighting(t_matter m, t_light light, t_comput eye)
{
	t_vect	lightv;
	t_vect	reflectv;
	t_color	color;
	double	light_dot_normal;
	double	reflect_dot_eye;

	eye.effective = color_operators(m.color, light.color, 0, HAMADAR);
	lightv = normalize(vect_operators(light.pos, eye.hit_point, 0, SUBTRACT));
	eye.ambient = color_operators(eye.effective, m.ambient, 0, HAMADAR);
	light_dot_normal = dot(lightv, eye.normal);
	reflect_dot_eye = 0;
	if (light_dot_normal >= 0)
	{
		reflectv = reflect(vect_operators(lightv, (t_tuple){0}, 0, \
		NEGATE), eye.normal);
		reflect_dot_eye = dot(reflectv, eye.eye);
	}
	color = color_operators(eye.ambient, diffuse(m, light_dot_normal, \
	eye.effective, light), 0, ADD);
	return (color_operators(color, specular(m, light, light_dot_normal, \
	reflect_dot_eye), 0, ADD));
}
