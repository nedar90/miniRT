/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:40:23 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/24 12:12:53 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stddef.h>
# include <math.h>
# include <MLX42.h>
# include <stdbool.h>
# include "operators.h"
# include "libft.h"

/*..........................MAIN_UTILS..................*/
t_scene		create_scene(void);
t_camera	new_camera(void);
void		init_canvas(t_camera *camera);
void		init(t_scene *scene, char *file_name);
void		check_file_name(char *filename);

/*                      INIT_OBJ                          */
void		init_sp(t_objects *obj);
void		init_pl(t_objects *obj);
void		init_cy(t_objects *obj);

/*                      UTILS                          */
bool		is_in_range(double *add, double num, double min, double max);
bool		is_normalized(t_vect normal);
void		check_size(char **str, int size);
void		comma_handler(char *str);

/*                      MENU                          */
void		print_menu(t_scene scene);

/*                      PARSER                        */
int			parser(t_scene *scene, char *file);
int			parse_sp(t_scene *scene, char **data);
int			parse_cy(t_scene *scene, char **data);
int			parse_pl(t_scene *scene, char **data);
int			parse_cam(t_scene *scene, char **data);
int			parse_amb(t_scene *scene, char **data);
int			parse_light(t_scene *scene, char **data);

void		fill_tuple(t_vect *vect, char *str, double min, double max);
void		fill_color(t_color *color, char *str);

/*                     CAMERA                          */
void		init_canvas(t_camera *camera);
void		set_camera(t_camera *camera);
t_matrix	view_transform(t_point from, t_point to, t_vect up);

/*                     CANVAS                          */
void		render(void *param);

/*                     RAY                          */
t_ray		new_ray(t_vect point, t_vect direction);
t_ray		transform(t_ray r, t_matrix m);

/*                     INTERSECTION                        */
int			intersection(t_objects objs, t_ray *ray);
t_color		set_color(t_scene *scene, t_ray *ray);

/*                   SPHERE                      */
bool		intersection_sphere(struct s_objects obj, t_ray *ray);
t_vect		normal_at_sphere(struct s_objects *obj, t_point object_point);

/*                   PLANE                      */
bool		intersection_plane(struct s_objects obj, t_ray *ray);
t_vect		normal_at_plane(struct s_objects *obj, t_point object_point);

/*                   CYLINDER                      */
bool		intersection_cylinder(struct s_objects obj, t_ray *ray);
t_vect		normal_at_cylinder(struct s_objects *obj, t_point object_point);
bool		check_time_interval(t_objects obj, t_ray *ray, double t);
double		ft_min(double *num);
void		intersect_caps(t_objects obj, t_ray *ray, double time[4]);

/*                   CYLINDER_UTILS                      */
bool		intersection_cylinder(struct s_objects obj, t_ray *ray);

/*                      LIBFT                          */
void		free_scene(t_scene *scene);
t_objects	*ft_lstnew(void);
void		ft_lstadd_front(t_objects **lst, t_objects *new);
void		ft_lstadd_light(t_light **lst, t_light *new);

/*                      LIGHT                          */
t_vect		normal_at(t_objects obj, t_point world_point);
void		set_transform(t_objects *obj, t_matrix translate, t_matrix scale);
t_color		lighting(t_matter m, t_light light, t_comput eye);

/*                      SHADOW                          */
bool		is_inshadow(t_scene scene, t_point point, \
t_vect normal, t_light light);

/*                      PUT PIXEL                          */
void		my_put_pixel(mlx_image_t *image, \
uint32_t x, uint32_t y, uint32_t color);
void		keyhook(mlx_key_data_t keydata, void *param);

/*............................RENDER.....................*/
t_ray		ray_to_pixel(t_camera *camera, double x, double y);
void		render(void *param);
t_tuple		reflect(t_tuple in, t_tuple normal);

#endif
