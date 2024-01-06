/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:39:34 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 10:08:27 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	multiply_matrices(t_matrix a, t_matrix b)
{
	double		m[MAX][MAX];
	size_t		row;
	size_t		col;

	ft_memset(m, '\0', sizeof(double) * M_SIZE);
	row = -1;
	while (++row < MAX)
	{
		col = -1;
		while (++col < MAX)
		{
			m[row][col] = a.matrix[row][0] * b.matrix[0][col]
				+ a.matrix[row][1] * b.matrix[1][col]
				+ a.matrix[row][2] * b.matrix[2][col]
				+ a.matrix[row][3] * b.matrix[3][col];
		}
	}
	return (new_matrix(m, MAX));
}

t_tuple	multiply_mx_tp(t_matrix a, t_tuple b)
{
	double	t[MAX];
	int		row;

	row = -1;
	while (++row < MAX)
	{
		t[row] = a.matrix[row][0] * b.x \
			+ a.matrix[row][1] * b.y \
			+ a.matrix[row][2] * b.z \
			+ a.matrix[row][3] * b.w; 
	}
	return (new_tuple(t[0], t[1], t[2], t[3]));
}
