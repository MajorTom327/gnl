/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:37:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/26 07:05:40 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

static void	save(char **line, char *str)
{
	static char saved[BUFF_SIZE];

	if (str == NULL)
	{
		if (saved[0] != 0)
			ft_strcat(*line, saved);
	}
	else
		ft_strcpy(saved, str);
}

int			get_next_line(int const fd, char **line)
{
	char	*tmp;
	int		i;

	i = 1;
	ft_strclr(*line);
	tmp = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || line == NULL || tmp == NULL)
		return (-1);
	save(line, NULL);
	while (i != 0)
	{
		i = read(fd, tmp, BUFF_SIZE);
		if (ft_strchr(tmp, '\n') != NULL)
		{
			*ft_strchr(tmp, '\n') = '\0';
			save(NULL, ft_strchr(tmp, '\0') + 1);
			ft_strcat(*line, tmp);
			return (1);
		}
		ft_strcat(*line, tmp);
		if (i < BUFF_SIZE)
			return (0);
	}
	return (1);
}
