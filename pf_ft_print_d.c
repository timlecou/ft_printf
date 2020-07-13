/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:31:22 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/05 18:45:03 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ft_left_neg_d(t_op *op, int nb)
{
	char	*ptr;
	int		len;

	ptr = pf_ft_itoa_d(nb);
	len = (int)ft_strlen(ptr);
	pf_ft_write(op, 1, "-", 1);
	if (op->is_prec)
	{
		while (op->prec > len)
		{
			pf_ft_write(op, 1, "0", 1);
			len++;
		}
	}
	pf_ft_write(op, 1, ptr, (int)ft_strlen(ptr));
	while (op->width-- > len + 1)
		pf_ft_write(op, 1, " ", 1);
	free(ptr);
}

void	pf_ft_left_pos_d(t_op *op, int nb)
{
	char	*ptr;
	int		len;

	ptr = ft_itoa(nb);
	len = (int)ft_strlen(ptr);
	while (op->prec > len)
	{
		pf_ft_write(op, 1, "0", 1);
		len++;
	}
	pf_ft_write(op, 1, ptr, (int)ft_strlen(ptr));
	while (op->width-- > len)
		pf_ft_write(op, 1, " ", 1);
	free(ptr);
}

void	pf_ft_rigth_neg_d(t_op *op, int nb)
{
	char	*ptr;
	int		len;

	ptr = pf_ft_itoa_d(nb);
	len = (op->prec < (int)ft_strlen(ptr)) ? (int)ft_strlen(ptr) : op->prec;
	if (op->is_zero == 1 && !op->is_prec)
	{
		pf_ft_write(op, 1, "-", 1);
		while (op->width-- > len + 1)
			pf_ft_write(op, 1, "0", 1);
	}
	else
	{
		while (op->width-- > len + 1)
			pf_ft_write(op, 1, " ", 1);
		pf_ft_write(op, 1, "-", 1);
		while (op->prec-- > (int)ft_strlen(ptr))
			pf_ft_write(op, 1, "0", 1);
	}
	pf_ft_write(op, 1, ptr, (int)ft_strlen(ptr));
	free(ptr);
}

void	pf_ft_rigth_pos_d(t_op *op, int nb)
{
	char	*ptr;
	int		len;

	ptr = ft_itoa(nb);
	len = (op->prec < (int)ft_strlen(ptr)) ? (int)ft_strlen(ptr) : op->prec;
	if (!op->is_prec && op->is_zero)
	{
		while (op->width-- > len)
			pf_ft_write(op, 1, "0", 1);
	}
	else
	{
		while (op->width-- > len)
			pf_ft_write(op, 1, " ", 1);
		while (op->prec-- > (int)ft_strlen(ptr))
			pf_ft_write(op, 1, "0", 1);
	}
	pf_ft_write(op, 1, ptr, (int)ft_strlen(ptr));
	free(ptr);
}

void	pf_ft_print_d(va_list *list, t_op *op)
{
	int	nb;

	nb = va_arg(*list, int);
	if (nb == 0 && op->is_prec && !op->prec)
	{
		while (op->width--)
			pf_ft_write(op, 1, " ", 1);
	}
	else if (op->left == 1)
	{
		if (nb < 0)
			pf_ft_left_neg_d(op, nb);
		else
			pf_ft_left_pos_d(op, nb);
	}
	else
	{
		if (nb < 0)
			pf_ft_rigth_neg_d(op, nb);
		else
			pf_ft_rigth_pos_d(op, nb);
	}
}
