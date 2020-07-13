/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:49:17 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/05 19:28:28 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ft_left_p(t_op *op, uintptr_t nb)
{
	int		len;
	char	*ptr;

	len = pf_ft_size_uintptr_t(nb) + 2;
	pf_ft_write(op, 1, "0x", 2);
	if (nb == 0 && op->is_prec && !op->prec)
		return ;
	while (op->prec > (len - 2))
	{
		pf_ft_write(op, 1, "0", 1);
		op->prec--;
	}
	ptr = pf_ft_itoa_base_p(nb, 1);
	pf_ft_write(op, 1, ptr, (int)ft_strlen(ptr));
	free(ptr);
	while (op->width > len)
	{
		pf_ft_write(op, 1, " ", 1);
		op->width--;
	}
}

void	pf_ft_rigth_p(t_op *op, uintptr_t nb)
{
	int		len;
	char	*ptr;

	len = pf_ft_size_uintptr_t(nb) + 2;
	while (op->width > len)
	{
		pf_ft_write(op, 1, " ", 1);
		op->width--;
	}
	pf_ft_write(op, 1, "0x", 2);
	if (nb == 0 && op->is_prec && !op->prec)
		return ;
	while ((len - 2) < op->prec)
	{
		pf_ft_write(op, 1, "0", 1);
		len++;
	}
	ptr = pf_ft_itoa_base_p(nb, 1);
	pf_ft_write(op, 1, ptr, (int)ft_strlen(ptr));
	free(ptr);
}

void	pf_ft_print_p(va_list *list, t_op *op)
{
	uintptr_t	ptr;

	ptr = va_arg(*list, uintptr_t);
	if (ptr == 0 && op->is_prec && !op->prec)
	{
		if (op->left == 1)
		{
			pf_ft_write(op, 1, "0x", 2);
			while (op->width-- > 2)
				pf_ft_write(op, 1, " ", 1);
		}
		else
		{
			while (op->width-- > 2)
				pf_ft_write(op, 1, " ", 1);
			pf_ft_write(op, 1, "0x", 2);
		}
	}
	else if (op->left == 1)
		pf_ft_left_p(op, ptr);
	else
		pf_ft_rigth_p(op, ptr);
}
