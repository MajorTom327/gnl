/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 20:32:11 by vthomas           #+#    #+#             */
/*   Updated: 2016/08/01 20:34:22 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_stradd(char **dst, const char *src)
{
	char	*tmp;

	tmp = ft_strdup(*dst);
	ft_strdel(dst);
	*dst = ft_strnew(ft_strlen(tmp) + ft_strlen(src));
	ft_strcat(*dst, tmp);
	ft_strcat(*dst, src);
	ft_strdel(&tmp);
}
