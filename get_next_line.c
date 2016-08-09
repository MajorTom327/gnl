/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/09 09:31:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"
#include "libft/libft.h"
#include "debug.h"

static int sf_save(char **line, int state)
{
	static char *str_save = NULL;

	dbg_var_str("sf_save", "str_save", str_save, 3);
	if (state)
	{
		if (str_save == NULL)
			return (0);
		*line = ft_strdup(str_save);
		ft_strclr(str_save);
		dbg_var_str("sf_save", "*line", *line, 3);
		if (ft_strchr(*line, '\n') != NULL)
			return ((int)(*ft_strchr(*line, '\n') = '\0') ? 1 : 1);
		return (2);
	}
	if (str_save != NULL)
		ft_bzero((void *)str_save, ft_strlen(str_save));
	ft_strdel(&str_save);
	str_save = ft_strdup(ft_strchr(*line, '\n') + 1);
	*ft_strchr(*line, '\n') = '\0';
	dbg_var_str("sf_save", "str_save", str_save, 3);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int		ret;
	char	*tmp;

	dbg_info("get_next_line", "Start GNL", 0);
	if (fd < 0 || line == NULL)
		return (-1);
	if ((ret = sf_save(line, 1)) == 1)
		return (1);
	else if (ret == 0)
		*line = ft_strnew(0);
	dbg_var_str("get_next_line", "*line", *line, 0);
	ret = BUFF_SIZE;
	tmp = ft_strnew(BUFF_SIZE);
	dbg_info("get_next_line", "Before while", 0);
	while ((ret = read(fd, tmp, BUFF_SIZE)) == BUFF_SIZE)
	{
		ft_stradd(line, tmp);
		if (ft_strchr(tmp, '\n'))
			break;
		ft_strclr(tmp);
	}
	dbg_info("get_next_line", "After while", 0);
	if (ft_strchr(*line, '\n') != NULL)
	{
		dbg_info("get_next_line", "BEFORE SAVE MOTHA FUCKA", 0);
		sf_save(line, 0);
		dbg_info("get_next_line", "AFTER SAVE MOTHA FUCKA", 0);
		return (1);
	}
	ft_stradd(line, tmp);
	dbg_var_str("get_next_line", "*line", *line, 0);
	if (!ft_strlen(*line))
		return (0);
	else
		return (1);
}
