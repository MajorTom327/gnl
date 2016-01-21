/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:37:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/01/21 07:40:16 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

static int	static_load(char *str, char *line)
{
	size_t i;
	int j;

	i = 0;
	j = 0;
	while (str[j] != '\n')
		j++;
	while (str[j] != '\0')
	{
		line[i] = str[j];
		i++;
		j++;
	}
	ft_putstr("STATIC_LOAD:");
	ft_putstr(str);
	return (++j);
}

int	get_next_line(int const fd, char **line)
{
	int			i;
	int			j;
	static char	*str = NULL;

	i = 0;
	j = 0;
	if (str == NULL)
		str = ft_strnew(BUFF_SIZE);
	else
		j = static_load(str, *line);
	if (str == NULL)
		return (-1);
	ft_strclr(line[0]);
	read(fd, str, BUFF_SIZE);
	while (str[i] != '\n' && str[i] != EOF)
	{
		line[0][j] = str[i];
		i++;
		j++;
		if (i != BUFF_SIZE)
			continue;
		i = 0;
		if (read(fd, str, BUFF_SIZE) == -1)
			return (-1);
	}
	if (str[i] == EOF)
		return (0);
	*line[i] = '\0';
	return (1);
}
