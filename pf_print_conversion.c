/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:54:45 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/03 18:30:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conversion(va_list *list, t_op *op)
{
	if (op->conv == 'd' || op->conv == 'i')
		pf_ft_print_d(list, op);
	else if (op->conv == 'c')
		pf_ft_print_c(list, op);
	else if (op->conv == 's')
		pf_ft_print_s(list, op);
	else if (op->conv == 'u')
		pf_ft_print_u(list, op);
	else if (op->conv == 'p')
		pf_ft_print_p(list, op);
	else if (op->conv == '%')
		pf_ft_print_per(op);
	else if (op->conv == 'x')
		pf_ft_print_x(list, op, 1);
	else if (op->conv == 'X')
		pf_ft_print_x(list, op, 2);
}
