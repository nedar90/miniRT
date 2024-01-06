/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:26:25 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 15:31:16 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *err, bool flag)
{
	int	len;

	len = 0;
	if (flag)
	{
		len = ft_strlen(err);
		write(STDERR_FILENO, "Error: ", 7);
		write(STDERR_FILENO, err, len);
	}
	else
		perror(err);
	exit(EXIT_FAILURE);
}
