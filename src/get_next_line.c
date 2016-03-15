/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:37:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/15 19:56:06 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

static void	save(char **line, char *str)
{
	static char	saved[BUFF_SIZE + 1];
	size_t		i;

	if (str == NULL)
	{
		i = 0;
		while (i != ft_strlen(saved))
		{
			if (saved[i] != '\n')
				break ;
			i++;
		}
		if (i != ft_strlen(saved))
			ft_strcat(*line, &saved[i]);
		ft_strclr(saved);
	}
	else
	{
		ft_strcpy(saved, str);
		*(str - 1) = '\n';
		*str = '\0';
	}
}

int			get_next_line(int const fd, char **line)
{
	char	*tmp;
	int		i;

	i = 1;
	ft_strclr(*line);
	tmp = ft_strnew(BUFF_SIZE + 2);
	if (fd < 0 || line == NULL || tmp == NULL)
		return (-1);
	save(line, NULL);
	while (i != 0)
	{
		i = read(fd, tmp, BUFF_SIZE + 1);
		if (ft_strchr(tmp, '\n') != NULL)
		{
			*ft_strchr(tmp, '\n') = '\0';
			save(NULL, &tmp[ft_strlen(tmp) + 1]);
			ft_strcat(*line, tmp);
			break ;
		}
		ft_strcat(*line, tmp);
		if (i < BUFF_SIZE + 1 || ft_strchr(*line, EOF) != NULL)
		{
			*line[ft_strlen(*line) - 3] = '\0';
			return (0);
		}
	}
	return (1);
}
