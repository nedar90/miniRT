/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:12:32 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:07:38 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_scene(t_scene *scene)
{
	t_objects	*obj;
	t_light		*light;

	while (scene->objs)
	{
		obj = scene->objs->next;
		free(scene->objs->content);
		free(scene->objs);
		scene->objs = obj;
	}
	while (scene->light)
	{
		light = scene->light->next;
		free(scene->light);
		scene->light = light;
	}
}
