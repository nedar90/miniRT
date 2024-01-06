/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:25:02 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/25 11:46:41 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <stdbool.h>

# define SCREEN_WIDTH	800
# define SCREEN_HIGHT	400
# define DBL_MAX		1.7976931348623157e+308
# define EPSILON		0.0001

# define MAX	4
# define M_SIZE	16

typedef enum s_menu
{
	ZOOM,
	MOVE_X,
	MOVE_Y,
	MOVE_Z
}		t_menu;

typedef enum s_objs
{
	SPHERE,
	CYLINDER,
	PLANE
}		t_objs;

typedef enum s_opts
{
	ADD,
	SUBTRACT,
	MULTI,
	DIVISION,
	NEGATE,
	HAMADAR,
}		t_opts;

typedef struct s_shearing
{
	double	s1;
	double	s2;
}	t_shearing;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}		t_color;

/**
 * @param w is 1 if tuple is a point and 
 * 0 if tuple is a vector
 * **/

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}		t_tuple;

typedef t_tuple	t_vect;

typedef t_tuple	t_point;

typedef struct s_matrix
{
	double	matrix[MAX][MAX];
	size_t	size;
}		t_matrix;

typedef struct s_comput
{
	t_point		hit_point;
	t_vect		eye;
	t_vect		normal;
	t_color		effective;
	t_color		ambient;
}		t_comput;

typedef struct s_camera
{
	t_point		origin;
	t_vect		direction;
	double		pic_width;
	double		pic_height;
	double		fov;
	double		pixel;
	t_matrix	transform;
	t_matrix	inverse;
}		t_camera;

typedef struct s_light
{
	t_vect			pos;
	t_color			color;
	bool			inshadow;
	t_matrix		transform;
	t_matrix		inverse;
	t_matrix		transpose;
	struct s_light	*next;
}		t_light;

typedef struct s_ray
{
	t_point	origin;
	t_vect	direction;
	double	t;
}		t_ray;

typedef struct s_sphere
{
	t_vect			pos;
	double			radius;
}		t_sphere;

typedef struct s_plane
{
	t_vect			pos;
	t_vect			normal_vect;
}		t_plane;

typedef struct s_param
{
	t_tuple		origin;
	t_tuple		direction;
	double		diameter;
	double		height;
}		t_param;

typedef struct cylinder
{
	t_vect			pos;
	bool			is_closed;
	double			radius;
	double			min_height;
	double			max_height;
}		t_cylinder;

typedef union s_union
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
}		t_union;

typedef struct s_matter
{
	t_color	color;
	t_color	ambient;
	double	diffusion;
	double	shining;
	double	specular;
}	t_matter;

typedef struct s_objects
{
	t_union				*content;
	bool				(*interection_obj)(struct s_objects	obj, t_ray	*ray);
	t_tuple				(*normal_at_obj)(struct s_objects	*obj, \
	t_point	object_point);
	t_matter			matter;
	t_matrix			transform;
	t_matrix			inverse;
	t_matrix			transpose;
	struct s_objects	*next;
}		t_objects;

typedef struct s_scene
{
	bool		has_camera;
	bool		has_ambient;
	void		*mlx;
	void		*img;
	t_light		*light;
	t_color		ambient;
	t_camera	camera;
	t_objects	*objs;
}		t_scene;

#endif
