/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:17:53 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:29:50 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	comma_handler(char *str)
{
	int		i;

	if (*str == ',')
		ft_error("comma", true);
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			ft_error("comma", true);
	}
	if (str[i - 1] == ',')
		ft_error("comma", true);
}

bool	is_normalized(t_vect normal)
{
	if (fabs(1.0 - magnitude(normal)) >= EPSILON)
		return (false);
	return (true);
}

bool	is_in_range(double *add, double num, double min, double max)
{
	if (num >= min && num <= max)
	{
		*add = num;
		return (true);
	}
	return (false);
}

void	check_size(char **str, int size)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != size)
		ft_error("size", true);
}
