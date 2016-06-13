/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/13 03:06:23 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "debug.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char *str;
	int fd;
	int ret;
	int	turn;

	dbg_title("start");
	if (ac == 1)
		fd = open("./test", O_RDONLY);
	else
	{
		dbg_var_str("main", "file", av[1], 1);
		fd = open(av[1], O_RDONLY);
	}
	dbg_info("main","Open \t\tOK", 1);
	str = ft_strnew(100);
	dbg_info("main","String creation \tOK", 1);
	turn = 0;
	while ((ret = get_next_line(fd, &str)) == 1 && turn < 10)
	{
		ft_putnbr_desc("turn:\t", turn);
		dbg_var_int("main","turn", turn, 1);
		dbg_var_int("main","ret", ret, 1);
		dbg_var_str("main","str", str, 1);
		ft_putendl(str);
		dbg_breakpoint("main", 1);
		turn++;
	}
	dbg_var_int("main", "nbr of 1", turn, 1);
	ft_putendl(str);
	close(fd);
	dbg_title("end");
	return (EXIT_SUCCESS);
}
