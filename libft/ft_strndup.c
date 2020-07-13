/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:21:35 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/01 17:33:46 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_slen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strndup(const char *str, int len)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (ft_slen(str) + 1))))
		return (NULL);
	while (str[i] != '\0' && len)
	{
		res[i] = str[i];
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
