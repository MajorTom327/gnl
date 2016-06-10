/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/10 03:16:57 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <debug.h>
#include "get_next_line.h"
#include "libft.h"

static char	*res_str(char *str)
{
	int i;
	int j;

	i = (int)(ft_strchr(str, '\n') - str);
	j = 0;
	dbg_var_str("res_str", "str", str, 4);
	while (str[i] != '\0')
	{
		str[j] = str[i];
		str[i] = '\0';
		i++;
		j++;
	}
	dbg_var_str("res_str", "str", str, 4);
	return (str);
}

static void	f_purge(char *str)
{
	while (*str != '\n' && *str != '\0')
		str++;
	while (*str != '\0')
	{
		*str = '\0';
		str++;
	}
}

static int	save_str(char *line, int s)
{
	static char	*save = NULL;
	int			size;

	dbg_var_int("save_str", "Entering in with", s, 3);
	if (save == NULL && !s)
		return (0);
	if (s)
	{
		if (save != NULL)
			ft_memdel((void **)&save);
		save = ft_strdup(line);
		return (1);
	}
	if (!s)
	{
		ft_strclr(line);
		size = save - ft_strchr(save, '\n');

		line = ft_strnew(ft_strlen(save));
		line = ft_strdup(save);
		//ft_strclr(save);
		dbg_var_str("save_str", "save", save, 3);
		save = res_str(save);
		f_purge(line);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int		ret;
	char	*tmp;

	dbg_title("get_next_line");
	if (fd == -1)
		return (-1);
	save_str(*line, 0);
	tmp = ft_strnew(BUFF_SIZE);
	dbg_var_int("get_next_line", "BUFF_SIZE", BUFF_SIZE, 2);
	ret = BUFF_SIZE;
	while (ft_strchr(tmp, '\n') == NULL && ret == BUFF_SIZE)
	{
		ret = read(fd, tmp, BUFF_SIZE);
		dbg_var_int("get_next_line", "ret", ret, 2);
		ft_strcat(*line, tmp);
	}
	if (ret < BUFF_SIZE)
		return (0);
	save_str(ft_strchr(*line, '\n'), 1);
	f_purge(ft_strchr(*line, '\n'));
	return (1);
}
