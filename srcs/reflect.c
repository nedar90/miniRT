/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:43:47 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 17:17:06 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	tuple;

	tuple = vect_operators(normal, (t_tuple){0},
			2 * dot(in, normal), MULTI);
	tuple = vect_operators(in, tuple, 0, SUBTRACT);
	return (tuple);
}
