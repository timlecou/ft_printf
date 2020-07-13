/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:14:31 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/03 19:13:15 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ft_left_c(t_op *op, char c)
{
	pf_ft_write(op, 1, &c, 1);
	while (op->width-- > 1)
		pf_ft_write(op, 1, " ", 1);
}

void	pf_ft_rigth_c(t_op *op, char c)
{
	while (op->width-- > 1)
	{
		if (op->is_zero)
			pf_ft_write(op, 1, "0", 1);
		else
			pf_ft_write(op, 1, " ", 1);
	}
	pf_ft_write(op, 1, &c, 1);
}

void	pf_ft_print_c(va_list *list, t_op *op)
{
	char	c;

	c = (unsigned char)va_arg(*list, int);
	if (op->left == 1)
		pf_ft_left_c(op, c);
	else
		pf_ft_rigth_c(op, c);
}
