/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/09 12:06:59 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"
#include "libft/libft.h"

static int	sf_save(char **line, int state)
{
	static char *str_save = NULL;

	if (state)
	{
		if (str_save == NULL)
			return (0);
		*line = ft_strdup(str_save);
		ft_strclr(str_save);
		if (ft_strchr(*line, '\n') != NULL)
			return ((int)(*ft_strchr(*line, '\n') = '\0') ? 1 : 1);
		return (2);
	}
	if (str_save != NULL)
		ft_strclr(str_save);
	ft_strdel(&str_save);
	str_save = ft_strdup(ft_strchr(*line, '\n') + 1);
	*ft_strchr(*line, '\n') = '\0';
	return (0);
}

//TODO: Make a function for the test

int			get_next_line(const int fd, char **line)
{
	int		ret;
	char	*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((ret = sf_save(line, 1)) == 1)
		return (1);
	else if (ret == 0)
		*line = ft_strnew(0);
	ret = BUFF_SIZE;
	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, tmp, BUFF_SIZE)) == BUFF_SIZE)
	{
		ft_stradd(line, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
		ft_strclr(tmp);
	}
	//TODO: Function must do that if
	if (ft_strchr(*line, '\n') != NULL)
	{
		sf_save(line, 0);
		return (1);
	}
	ft_stradd(line, tmp);
	if (ft_strchr(*line, '\n') != NULL)
	{
		sf_save(line, 0);
		return (1);
	}
	if (!ft_strlen(*line))
		return (0);
	else
		return (1);
}
