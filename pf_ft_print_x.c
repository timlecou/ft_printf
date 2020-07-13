/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:49:56 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/05 19:07:35 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ft_lepf_ft_x(t_op *op, uintmax_t nb, int n)
{
	int		nb_len;
	char	*ptr;

	nb_len = pf_ft_get_size_x(nb);
	if (nb == 0 && op->is_prec && !op->prec)
	{
		while (op->width--)
			pf_ft_write(op, 1, " ", 1);
		return ;
	}
	while (nb_len++ < op->prec)
		pf_ft_write(op, 1, "0", 1);
	ptr = pf_ft_itoa_base_x(nb, n);
	pf_ft_write(op, 1, ptr, pf_ft_get_size_x(nb));
	free(ptr);
	while (op->width-- >= nb_len)
		pf_ft_write(op, 1, " ", 1);
}

void	pf_ft_x(t_op *op, int nb)
{
	int	n;

	n = (nb < op->prec) ? op->prec : nb;
	if (!op->is_prec)
	{
		while (op->width-- > nb)
		{
			if (op->is_zero)
				pf_ft_write(op, 1, "0", 1);
			else
				pf_ft_write(op, 1, " ", 1);
		}
	}
	else
	{
		while (op->width-- > n)
			pf_ft_write(op, 1, " ", 1);
	}
}

void	pf_ft_rigth_x(t_op *op, uintmax_t nb, int n)
{
	int		nb_len;
	char	*ptr;

	(void)n;
	nb_len = pf_ft_get_size_x(nb);
	if (nb == 0 && op->is_prec && !op->prec)
	{
		while (op->width--)
			pf_ft_write(op, 1, " ", 1);
		return ;
	}
	pf_ft_x(op, nb_len);
	while (nb_len++ < op->prec)
		pf_ft_write(op, 1, "0", 1);
	ptr = pf_ft_itoa_base_x(nb, n);
	pf_ft_write(op, 1, ptr, pf_ft_get_size_x(nb));
	free(ptr);
}

void	pf_ft_print_x(va_list *list, t_op *op, int n)
{
	unsigned int	nb;

	nb = va_arg(*list, unsigned int);
	if (op->left == 1)
		pf_ft_lepf_ft_x(op, nb, n);
	else
		pf_ft_rigth_x(op, nb, n);
}
