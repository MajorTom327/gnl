/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/18 15:30:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include "debug.h"

int	main(int ac, char **av)
{
	char	*str;
	int		fd;
	int		ret;
	int		turn;

	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = open("./f_test", O_RDONLY);
	if (fd < 1)
		exit(EXIT_FAILURE);
	turn = 0;
	dbg_var_int("main", "BUFF_SIZE", BUFF_SIZE, 0);
	dbg_title("WHILE");
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		turn++;
		dbg_var_int("main", "line", turn, 0);
		dbg_var_str("main", "str", str, 0);
//		ft_putendl(str);
	}
	dbg_title("END OF WHILE");
	dbg_var_int("main", "nbr_line", turn, 0);
	close(fd);
	return (EXIT_SUCCESS);
}
