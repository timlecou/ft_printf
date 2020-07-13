/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 14:47:01 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/03 11:25:17 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_ft_do_printf(const char *str, va_list *list, int i)
{
	t_op	op;
	int		ret;
	char	*ptr;

	ret = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ptr = ft_strdup(&str[i]);
			op = pf_ft_fill_op(ptr, list);
			print_conversion(list, &op);
			i += pf_ft_op_size(ptr, &op) - 1;
			ret += op.char_nb;
			free(ptr);
		}
		else if (str[i] != '%' && str[i] != '\0')
		{
			write(1, &str[i], 1);
			ret++;
		}
	}
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list	list;
	int		ret;

	ret = 0;
	va_start(list, str);
	ret = pf_ft_do_printf(str, &list, -1);
	va_end(list);
	return (ret);
}
