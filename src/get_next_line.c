#include "get_next_line.h"
#include <unistd.h>

static char *get_before_eol(char *str)
{
	char *c_eol;
	char *ret;

	c_eol = ft_strchr(str, '\n');
	ret = ft_strnew(ft_strlen(str));
	ft_strncpy(ret, str, (c_eol - str));
	return (ret);
}

static int get_save(char *line, int get)
{
	static char *str = NULL;

	if (get && str)
	{
		ft_memdel(*line);
		*line = get_before_eol(str);
		ft_strdup(str, ft_strchr(str, '\n'));
		return (1);
	}
	str = ft_strdup(line, ft_strchr(line, '\n'));
	return (0);
}

int	get_next_line(int const fd, char **line)
{
	char *tmp;

	if (get_save(*line, 1))
		return (1);
	tmp = ft_strnew(BUFF_SIZE);
	while (ft_strchr(tmp, NULL))
	{
		read(1, tmp, BUFF_SIZE);
		ft_strcat(*line, tmp);
	}
	if ()

	return (0);
}
