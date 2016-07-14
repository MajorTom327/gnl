/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/07/14 02:28:13 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"
#include "libft/libft.h"

static void	sf_addtostr(char **dst, const char *src)
{
	char	*tmp;

	tmp = ft_strdup(*dst);
	ft_strdel(dst);
	*dst = ft_strnew(ft_strlen(tmp) + ft_strlen(src));
	ft_strcat(*dst, tmp);
	ft_strcat(*dst, src);
	ft_strdel(&tmp);
}

static void	sf_repstart(char **str)
{
	char *tmp;
	char *eol;

	tmp = ft_strdup(*str);
	eol = ft_strchr(tmp, '\n');
	ft_strdel(str);
	if (eol != NULL)
		*str = ft_strdup(eol + 1);
	ft_strdel(&tmp);
}

static int	sf_save(char **str, int st)
{
	static char *save = NULL;

	if (st)
		ft_strdel(&save);
	if (*str == NULL)
	{
		if (save == NULL)
		{
			*str = ft_strnew(0);
			return (0);
		}
		*str = ft_strdup(save);
		if (ft_strchr(*str, '\n') != NULL)
		{
			*ft_strchr(*str, '\n') = '\0';
			sf_repstart(&save);
			return (1);
		}
		ft_strdel(&save);
		return (0);
	}
	save = ft_strdup(*str);
	return (0);
}

static int	sf_clear(char **str, int i)
{
	if (i)
		return (1);
	sf_save(str, 1);
	ft_strdel(str);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char	*tmp;
	int		ret;

	if (fd == -1 || line == NULL)
		return (-1);
	*line = NULL;
	if (sf_save(line, 0))
		return (1);
	ret = BUFF_SIZE;
	//BOUCLE DE LECTURE PRINCIPALE
	while (ft_strchr(*line, '\n') == NULL && ret == BUFF_SIZE)
	{
		tmp = ft_strnew(BUFF_SIZE);
		ret = read(fd, tmp, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		sf_addtostr(line, tmp);
		ft_strdel(&tmp);
	}
	//FIN DE LECTURE
	if ((tmp = ft_strchr(*line, '\n')))
	{
		*tmp = '\0';
		tmp++;
		//SAUVEGARDE DU RENDU EN TROP
		sf_save(&tmp, 0);
	}
	return (sf_clear(line, ft_strlen(*line)));//CLEAR && RETURN
}
