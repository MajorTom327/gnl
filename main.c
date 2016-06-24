/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:43:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/06/24 03:37:21 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char *str;
	int fd;
	int ret;
	int	turn;

	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = open("./f_test", O_RDONLY);
	str = ft_strnew(100);
	turn = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		turn++;
		ft_putendl(str);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
