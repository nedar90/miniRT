/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:29:35 by nrajabia          #+#    #+#             */
/*   Updated: 2023/12/23 16:08:37 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	shift_line(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = FALSE;
	while (str[i])
	{
		if (flag)
			str[j++] = str[i];
		if (str[i] == '\n')
			flag = TRUE;
		str[i++] = '\0';
	}
	return (flag);
}

size_t	ft_strlen_get(const char *str)
{
	int	count;

	count = 0;
	while (str && *str)
	{
		count++;
		if (*str == '\n')
			break ;
		str++;
	}
	return (count);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*ptr;
	int		num;

	if (s2[0] == '\0')
		return (NULL);
	ptr = (char *)malloc((ft_strlen_get(s1) + ft_strlen_get(s2) +1) \
	* sizeof(char));
	if (!ptr)
		return (NULL);
	num = 0;
	while (s1 && s1[num])
	{
		ptr[num] = s1[num];
		num++;
	}
	while (s2 && *s2 && *s2 != '\n')
		ptr[num++] = *s2++;
	if (*s2 == '\n')
		ptr[num++] = '\n';
	ptr[num] = '\0';
	if (s1)
		free(s1);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE +1];
	char		*line;
	int			num;

	if (BUFFER_SIZE < 1 || fd == -1 || FOPEN_MAX < fd)
		return (NULL);
	line = ft_strjoin_get(0, buff);
	if (shift_line(buff))
		return (line);
	num = read(fd, buff, BUFFER_SIZE);
	if (num < 0)
	{
		free(line);
		return (NULL);
	}
	while (num > 0)
	{
		line = ft_strjoin_get(line, buff);
		if (shift_line(buff))
			break ;
		num = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}
