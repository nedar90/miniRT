/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:57:16 by nrajabia          #+#    #+#             */
/*   Updated: 2023/10/18 11:33:50 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_H
# define OPERATORS_H

# include <math.h>
# include <stdio.h>
# include "objects.h"

/*                     VECTOR                           */
t_tuple			vect_operators(t_tuple a, t_tuple b, double scalar, int opt);
t_tuple			normalize(t_tuple v);
t_tuple			cross(t_tuple v1, t_tuple v2);
t_tuple			reflect(t_tuple in, t_tuple normal);
double			magnitude(t_tuple v);
double			dot(t_tuple v1, t_tuple v2);

/*                     COLOUR                           */
t_color			color_operators(t_color c1, t_color c2, double scalar, int opt);
int				rgb_to_color(t_color rgb);

/*                     MATRICES                           */
/*-----mx-utils------*/
unsigned int	compare_mx(t_matrix a, t_matrix b);
bool			is_invertible(t_matrix matrix);
t_matrix		identity_mx(void);
t_matrix		transpose_mx(t_matrix matrix);

/*                     RAY                           */
t_point			position(t_ray ray);

/*-----mx-rotation------*/
//static void	get_rotation_angles(t_vect vec, double *x, double *z);
t_matrix		rotate_x(double rad);
t_matrix		rotate_y(double rad);
t_matrix		rotate_z(double rad);
t_matrix		rotate_mx(t_vect vector);

/*-----mx-transformation------*/
t_matrix		translate_mx(t_tuple t);
t_matrix		scale_mx(double x, double y, double z);
t_matrix		shear_mx(t_shearing x, t_shearing y, t_shearing z);

/*-----mx-operations------*/
t_matrix		multiply_matrices(t_matrix a, t_matrix b);
t_tuple			multiply_mx_tp(t_matrix a, t_tuple b);

/*-----mx-inversion------*/
double			determinant(t_matrix matrix);
t_matrix		inverse_matrix(t_matrix matrix);

/*                   NEW ATTRIBUTES                      */
t_tuple			new_tuple(double x, double y, double z, double w);
t_tuple			new_point(double x, double y, double z);
t_vect			new_vector(double x, double y, double z);
t_color			new_color(double r, double g, double b);
t_matrix		new_matrix(const double table[MAX][MAX], size_t size);

#endif