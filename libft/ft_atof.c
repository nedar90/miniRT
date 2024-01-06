/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:35:14 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:30:46 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_number(const char *nptr, int i)
{
	bool	flag;
	double	number;
	double	frac;

	number = 0.0;
	frac = 1.0;
	flag = false;
	while (ft_isdigit(nptr[i]) || nptr[i] == '.')
	{
		if (nptr[i] != '.')
			number = number * 10 + nptr[i] - 48;
		if (flag)
			frac *= 10;
		if (nptr[i] == '.')
			flag = true;
		i++;
	}
	if (nptr[i] && nptr[i] != '\n' && !ft_isdigit(nptr[i]))
		ft_error("only number", true);
	return (number / frac);
}

double	ft_atof(const char *nptr)
{
	double	number;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while (nptr[i] == ' '
		|| (nptr[i] >= 10 && nptr[i] <= 13)
		|| nptr[i] == '\t')
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	number = get_number(nptr, i);
	return (sign * number);
}
