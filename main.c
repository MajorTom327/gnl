/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/14 02:04:38 by vthomas          ###   ########.fr       */
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

//	dbg_title("START");
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = open("./f_test", O_RDONLY);
	if (fd < 1)
		exit(EXIT_FAILURE);
	turn = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		turn++;
//		dbg_var_str("main", "str", str, 0);
//		if (turn >= 8)
//			break;
		ft_putendl(str);
	}
//	if (turn == 1)
//		ft_putstr("\033[31m");
//	else
//		ft_putstr("\033[32m");
//	ft_putnbr_desc("nb of turn:\t", turn);
//	ft_putstr("\033[0m");
	close(fd);
//	dbg_title("END");
	return (EXIT_SUCCESS);
}
