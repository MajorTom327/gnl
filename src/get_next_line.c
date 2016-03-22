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


static void	f_save(char **line, char *str)
{
	static char saved[BUFF_SIZE + 1];

	if (str == NULL)
	{
		ft_strclr(*line);
		ft_strcat(*line, saved);
		return ;
	}
	ft_strclr(saved);
	ft_strcat(saved, str);
}

int			get_next_line(int const fd, char **line)
{
	char	*str;

	if (fd < 0)
		return (-1);
	str = ft_strnew(BUFF_SIZE + 1);
	f_save(line, NULL);
	while (read(fd, str, BUFF_SIZE))
	{
		if (ft_strchr(str, '\n') == NULL)
		{
			ft_strcat(*line, str);
			continue;
		}
		*ft_strchr(str, '\n') = '\0';
		ft_strcat(*line, str);
		f_save(line, ft_strchr(str, '\0') + 1);
		return (1);
	}
	return (0);
}
