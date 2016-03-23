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
	size_t		i;

	if (str == NULL)
	{
		i = 0;
		ft_strclr(*line);
		while (saved[i] == '\n')
			i++;
		ft_strcat(*line, &saved[i]);
		return ;
	}
	ft_strclr(saved);
	ft_strcat(saved, str);
}

int			get_next_line(int const fd, char **line)
{
	char	*str;
	size_t	i;

	if (fd < 0)
		return (-1);
	str = ft_strnew(BUFF_SIZE + 1);
	f_save(line, NULL);
	while (read(fd, str, BUFF_SIZE))
	{
		i = 0;
		if (ft_strchr(str, '\n') == NULL)
		{
			ft_strcat(*line, str);
			continue;
		}
		while (str[i] == '\n')
			i++;
		*ft_strchr(&str[i], '\n') = '\0';
		ft_strcat(*line, str);
		f_save(line, ft_strchr(str, '\0') + 1);
		return (1);
	}
	return (0);
}
