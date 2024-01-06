/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:10:38 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 10:00:58 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	minor(t_matrix matrix, size_t row, size_t col);

t_matrix	matrix_of_minors(t_matrix matrix, size_t row, size_t col)
{
	double	minor[MAX][MAX];
	size_t	r;
	size_t	c;

	if (matrix.size == 0)
		return (identity_mx());
	r = -1;
	while (++r < matrix.size - 1)
	{
		c = -1;
		while (++c < matrix.size - 1)
			minor[r][c] = matrix.matrix \
				[r + (r >= row)][c + (c >= col)];
	}
	return (new_matrix(minor, matrix.size - 1));
}

double	cofactor(t_matrix matrix, size_t row, size_t col)
{
	double		cofactor;

	cofactor = minor(matrix, row, col);
	if ((row + col) % 2 == 1)
		cofactor *= -1;
	return (cofactor);
}

double	determinant(t_matrix matrix)
{
	size_t	col;
	double	det;

	det = 0;
	if (matrix.size == 2)
		det = (matrix.matrix[0][0] * matrix.matrix[1][1]) \
			- (matrix.matrix[0][1] * matrix.matrix[1][0]);
	else
	{
		col = -1;
		while (++col < matrix.size)
			det += (matrix.matrix[0][col] * cofactor(matrix, 0, col));
	}
	return (det);
}

double	minor(t_matrix matrix, size_t row, size_t col)
{
	t_matrix	m;
	double		minor;

	m = matrix_of_minors(matrix, row, col);
	minor = determinant(m);
	return (minor);
}

t_matrix	inverse_matrix(t_matrix matrix)
{
	double	invert[MAX][MAX];
	double	deter;
	size_t	row;
	size_t	col;

	if (!is_invertible(matrix))
		return (identity_mx());
	deter = determinant(matrix);
	row = -1;
	while (++row < matrix.size)
	{
		col = -1;
		while (++col < matrix.size)
			invert[col][row] = \
				cofactor(matrix, row, col) / deter;
	}
	return (new_matrix(invert, MAX));
}
