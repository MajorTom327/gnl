#include "get_next_line.h"
#include "debug.h"
#include <fcntl.h>
#include "libft.h"

int	main(void)
{
	int		fd;
	char	*str;

	dbg_title("Debut du Main");
	fd = open("./lorem", O_RDONLY);
	if (fd == -1)
	{
		dbg_info("main", "ERROR OPENING", 0);
		return (EXIT_FAILURE);
	}
	dbg_info("main", "Open ok !", 0);
	str = ft_strnew(64);
	if (str == NULL)
		return (EXIT_FAILURE);
	dbg_info("main", "strnew ok !", 0);
	dbg_title("Debut du GNL");
	while (get_next_line(fd, &str))
		ft_putendl(str);
	close(fd);
	return (EXIT_SUCCESS);
}
