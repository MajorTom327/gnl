/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:51:28 by vthomas           #+#    #+#             */
/*   Updated: 2015/11/25 19:52:31 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_str;
	size_t	index;
	char	*str_conc;

	size_str = (ft_strlen(s1) + ft_strlen(s2));
	str_conc = ft_strnew(size_str);
	if (str_conc == NULL)
		return (NULL);
	index = 0;
	while (index < size_str)
	{
		if (index < ft_strlen(s1))
			str_conc[index] = s1[index];
		else
			str_conc[index] = s2[index - ft_strlen(s1)];
		index++;
	}
	return (str_conc);
}
