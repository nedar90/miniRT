/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:36:02 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:31:31 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objects	*ft_lstnew(void)
{
	t_objects	*node;

	node = malloc(sizeof(t_objects));
	if (!node)
		return (NULL);
	node->content = NULL;
	node->next = NULL;
	return (node);
}
