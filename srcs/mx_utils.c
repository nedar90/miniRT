/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:07:46 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 09:30:45 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

unsigned int	compare_mx(t_matrix a, t_matrix b)
{
	double	*ptr_a;
	double	*ptr_b;

	ptr_a = &a.matrix[0][0];
	ptr_b = &b.matrix[0][0];
	while (!fabs(*ptr_a - *ptr_b))
	{
		ptr_a++;
		ptr_b++;
	}
	return ((unsigned int)(*ptr_a - *ptr_b));
}

t_matrix	identity_mx(void)
{
	const double	i[MAX][MAX] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	};

	return (new_matrix(i, MAX));
}

/*
t_matrix	create_matrix(const double table[MAX][MAX], size_t size)
{
	t_matrix	m;

	m.size = size;
	ft_memmove(m.matrix, table, sizeof(double) * SIZE);
	return (m);
}

int	compare_matrix(t_matrix a, t_matrix b)
{
	return (ft_memcmp(a.matrix, b.matrix, sizeof(double) * SIZE));
}
*/
t_matrix	transpose_mx(t_matrix matrix)
{
	size_t	row;
	size_t	col;
	double	m[MAX][MAX];

	row = -1;
	while (++row < matrix.size)
	{
		col = -1;
		while (++col < matrix.size)
			m[col][row] = matrix.matrix[row][col];
	}
	return (new_matrix(m, matrix.size));
}

bool	is_invertible(t_matrix matrix)
{
	if (determinant(matrix) == 0)
		return (false);
	return (true);
}
