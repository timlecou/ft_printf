/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:21:51 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/05 20:48:22 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ft_left_u(t_op *op, unsigned int nb)
{
	int		len;
	char	*ptr;

	ptr = pf_ft_itoa_u(nb, op);
	len = (int)ft_strlen(ptr);
	if (op->is_prec)
	{
		while (len < op->prec)
		{
			pf_ft_write(op, 1, "0", 1);
			len++;
		}
	}
	pf_ft_write(op, 1, ptr, (int)ft_strlen(ptr));
	while (op->width-- > len)
		pf_ft_write(op, 1, " ", 1);
	free(ptr);
}

void	pf_ft_rigth_u(t_op *op, unsigned int nb)
{
	int		len;
	char	*ptr;

	ptr = pf_ft_itoa_u(nb, op);
	len = (op->prec < (int)ft_strlen(ptr)) ? (int)ft_strlen(ptr) : op->prec;
	if (!op->is_prec && op->is_zero)
	{
		while (op->width > len)
		{
			pf_ft_write(op, 1, "0", 1);
			op->width--;
		}
	}
	else
	{
		while (op->width-- > len)
			pf_ft_write(op, 1, " ", 1);
	}
	while (op->prec-- > (int)ft_strlen(ptr))
		pf_ft_write(op, 1, "0", 1);
	pf_ft_write(op, 1, ptr, (int)ft_strlen(ptr));
	free(ptr);
}

void	pf_ft_print_u(va_list *list, t_op *op)
{
	unsigned int	nb;

	nb = va_arg(*list, unsigned int);
	if (nb == 0 && op->is_prec && !op->prec)
	{
		while (op->width--)
			pf_ft_write(op, 1, " ", 1);
	}
	else if (op->left == 1)
		pf_ft_left_u(op, nb);
	else
		pf_ft_rigth_u(op, nb);
}
