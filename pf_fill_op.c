/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:30:10 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/03 11:36:29 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_ft_t(char *str, int i)
{
	while (ft_isdigit(str[i]) && str[i] != '\0')
		i++;
	return (i);
}

int		pf_ft_get_flags(t_op *op, char *format, int index)
{
	while (pf_ft_is_flag(format[index]) && format[index] != '\0')
	{
		if (format[index] == '-')
			op->left = 1;
		else if (format[index] == '0' && op->left != 1)
			op->is_zero = 1;
		index++;
	}
	return (index);
}

int		pf_ft_get_prec(t_op *op, char *format, int index, va_list *list)
{
	char	*ptr;
	int		i;

	i = 0;
	if (format[index] == '.')
	{
		index++;
		op->is_prec = 1;
		if (format[index] == '*')
		{
			op->prec = va_arg(*list, int);
			index++;
		}
		else if (ft_isdigit(format[index]))
		{
			if (!(ptr = malloc(sizeof(char) * pf_ft_t(format, index) + 1)))
				return (0);
			while (ft_isdigit(format[index]) && format[index] != '\0')
				ptr[i++] = format[index++];
			ptr[i] = '\0';
			op->prec = ft_atoi(ptr);
			free(ptr);
		}
	}
	return (index);
}

int		pf_ft_get_width(t_op *op, char *format, int index, va_list *list)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	if (format[index] == '*')
	{
		op->width = va_arg(*list, int);
		index++;
	}
	else if (ft_isdigit(format[index]))
	{
		if (!(ptr = (char*)malloc(sizeof(char) * pf_ft_t(format, index) + 1)))
			return (-1);
		while (ft_isdigit(format[index]) && format[index] != '\0')
		{
			ptr[i] = format[index];
			index++;
			i++;
		}
		ptr[i] = '\0';
		op->width = ft_atoi(ptr);
		free(ptr);
	}
	return (index);
}

t_op	pf_ft_fill_op(char *format, va_list *list)
{
	int		i;
	t_op	op;

	i = 0;
	op = pf_ft_init_op();
	i = pf_ft_get_flags(&op, format, i);
	i = pf_ft_get_width(&op, format, i, list);
	i = pf_ft_get_prec(&op, format, i, list);
	op.conv = format[i];
	pf_ft_last_change(&op);
	return (op);
}
