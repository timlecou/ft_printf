/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_per.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:14:31 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/06 16:15:37 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ft_left_per(t_op *op)
{
	pf_ft_write(op, 1, "%", 1);
	while (op->width > 1)
	{
		pf_ft_write(op, 1, " ", 1);
		op->width--;
	}
}

void	pf_ft_rigth_per(t_op *op)
{
	while (op->width > 1)
	{
		if (op->is_zero)
			pf_ft_write(op, 1, "0", 1);
		else
			pf_ft_write(op, 1, " ", 1);
		op->width--;
	}
	pf_ft_write(op, 1, "%", 1);
}

void	pf_ft_print_per(t_op *op)
{
	if (op->left == 1)
		pf_ft_left_per(op);
	else
		pf_ft_rigth_per(op);
}
