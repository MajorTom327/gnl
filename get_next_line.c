/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/19 02:33:17 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"
#include "libft/libft.h"
#include "debug.h"

static void	sf_repos(char **str)
{
	void *tmp;
	size_t l;

	tmp = ft_strchr(*str, '\n');
	if (tmp == NULL)
	{
		ft_strclr(*str);
		return ;
	}
	tmp++;
	l = ft_strlen(ft_strchr(*str, '\n'));
	ft_memmove((void *)*str, tmp, l + 1);
}

static int	sf_save(char **line, int state)
{
	static char *str_save = NULL;

	if (state)
	{
		if (str_save == NULL)
			return (0);
		*line = ft_strdup(str_save);
		sf_repos(&str_save);
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

static int	sf_finaltest(int ret, char **line, char *tmp)
{
	if (ret == -1)
		return (ret);
	if (ft_strchr(*line, '\n') != NULL)
	{
		sf_save(line, 0);
		return (1);
	}
	*line = free_join(*line, tmp);
	ft_strdel(&tmp);
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
		*line = free_join(*line, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
		ft_strclr(tmp);
	}
	return (sf_finaltest(ret, line, tmp));
}
