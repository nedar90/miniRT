/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:30:09 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 16:57:38 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

/* typedef struct s_list {
	void			*content;
	struct s_list	*next;
}		t_list;
 */
char		*get_next_line(int fd);
char		**ft_split(char *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
bool		ft_isdigit(int c);
size_t		ft_strlen(const char *s);
double		ft_atof(const char *nptr);
void		ft_free(char **str);
void		ft_error(char *err, bool flag);
void		*ft_memset(void *s, int c, size_t n);
void		ft_swap(double *n1, double *n2);

#endif
