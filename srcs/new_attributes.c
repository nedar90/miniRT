/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:44:07 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:26:21 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	new_tuple(double x, double y, double z, double w)
{
	return ((t_tuple){x, y, z, w});
}

t_tuple	new_point(double x, double y, double z)
{
	return (new_tuple(x, y, z, 1.0));
}

t_vect	new_vector(double x, double y, double z)
{
	return (new_tuple(x, y, z, 0.0));
}

t_color	new_color(double r, double g, double b)
{
	return ((t_color){r, g, b});
}

t_matrix	new_matrix(const double table[MAX][MAX], size_t size)
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	if (size > M_SIZE)
		return (identity_mx());
	m.size = size;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			m.matrix[i][j] = table[i][j];
	}
	return (m);
}
