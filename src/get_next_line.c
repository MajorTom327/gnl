/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/11 04:07:40 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <debug.h>

#include "get_next_line.h"
#include "libft.h"

static void	sf_repstart(char **str)
{
	char *tmp;
	char *eol;

	tmp = ft_strdup(*str);
	eol = ft_strchr(tmp, '\n');
	ft_strdel(str);
	*str = ft_strdup(eol + 1);
	ft_strdel(&tmp);
}

static int	sf_save(char **str)
{
	static char *save = NULL;

	dbg_info("sf_save", "start", 2);
	dbg_var_str("sf_save", "str", *str, 2);
	if (*str == NULL)
	{
		dbg_info("sf_save", "In first if", 2);
		if (save == NULL)
		{
			*str = ft_strnew(1);
			return (0);
		}
		*str = ft_strdup(save);
		dbg_info("sf_save", "dup with success", 2);
		if (ft_strchr(*str,'\n') != NULL)
		{
			dbg_info("sf_save", "In the second if", 2);
			*ft_strchr(*str, '\n') = '\0';
			sf_repstart(&save);
			return (1);
		}
		return (0);
	}
	dbg_var_str("sf_save", "save (at end)", save, 2);
	ft_strdel(&save);
	dbg_info("sf_save", "After clear", 2);
	save = ft_strdup(*str);
	return (0);
}

static void	sf_addtostr(char **dst, const char *src)
{
	char *tmp;

	tmp = ft_strdup(*dst);
	ft_strdel(dst);
	*dst = ft_strnew(ft_strlen(tmp) + ft_strlen(src));
	ft_strcat(*dst, tmp);
	ft_strcat(*dst, src);
	ft_strdel(&tmp);
}

int			get_next_line(const int fd, char **line)
{
	char	*tmp;
	int		ret;

	dbg_title("GET_NEXT_LINE");
	if (fd == -1)
		return (-1);
	ft_strdel(line);
	dbg_info("get_next_line", "After del n1", 1);
	tmp = ft_strnew(BUFF_SIZE);
	if (sf_save(line))//On recupere ancienne chaine
		return (1);//Si on a une chaine complete deja
	ret = BUFF_SIZE;
	dbg_info("get_next_line", "Before while", 1);
	dbg_var_str("get_next_line", "line", *line, 1);
	while (ft_strchr(*line, '\n') == NULL && ret == BUFF_SIZE)
	{
		dbg_info("get_next_line", "in the while", 1);
		ret = read(fd, tmp, BUFF_SIZE);
		sf_addtostr(line, tmp);
	}
	dbg_var_str("get_next_line", "*line", *line, 1);
	dbg_var_str("get_next_line", "tmp", tmp, 1);
	ft_strdel(&tmp);
	tmp = ft_strchr(*line, '\n');
	if (tmp != NULL)
	{
		*tmp = '\0';
		tmp++;
		sf_save(&tmp);
	}
	return (ret == BUFF_SIZE);
}
