/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:54:44 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/25 12:10:39 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_identifier(t_scene *scene, char **data)
{
	int			i;
	static void	*type[6][2] = {
	{"sp", parse_sp},
	{"cy", parse_cy},
	{"pl", parse_pl},
	{"C", parse_cam},
	{"A", parse_amb},
	{"L", parse_light},
	};

	i = -1;
	while (++i < 6)
	{
		if (!ft_strncmp(data[0], type[i][0], ft_strlen(data[0])))
		{
			((int (*)(t_scene (*scene), char **data))type[i][1])(scene, data);
			return ;
		}
	}
	ft_error("file", true);
}

int	parser(t_scene *scene, char *file)
{
	int		fd;
	char	**data;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("file", false);
	line = get_next_line(fd);
	while (line)
	{
		if (line && *line != '\n')
		{
			data = ft_split(line, ' ');
			fill_identifier(scene, data);
			ft_free(data);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
