/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/07/14 03:08:02 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

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
	ft_putendl("Start while");
	turn = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		turn++;
		if (turn > 3)
			break;
		ft_putendl(str);
		ft_putnbr_desc("last ret:\t", ret);
	}
	ft_putnbr_desc("last ret:\t", ret);
	close(fd);
	return (EXIT_SUCCESS);
}
