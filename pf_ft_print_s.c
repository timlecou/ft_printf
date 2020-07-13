/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:30:03 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/03 11:38:07 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ft_lepf_ft_s(t_op *op, char *str)
{
	int	j;
	int	len;

	j = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		j = 1;
	}
	len = (int)ft_strlen(str);
	if (op->is_prec && len > 0 && len > op->prec)
		len = op->prec;
	pf_ft_write(op, 1, str, len);
	while (op->width-- > len)
		pf_ft_write(op, 1, " ", 1);
	if (j == 1)
		free(str);
}

void	pf_ft_rigth_s(t_op *op, char *str)
{
	int	j;
	int	len;

	j = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		j = 1;
	}
	len = (int)ft_strlen(str);
	if (op->is_prec && len > 0 && len > op->prec)
		len = op->prec;
	while (op->width-- > len)
	{
		if (op->is_zero)
			pf_ft_write(op, 1, "0", 1);
		else
			pf_ft_write(op, 1, " ", 1);
	}
	pf_ft_write(op, 1, str, len);
	if (j == 1)
		free(str);
}

void	pf_ft_print_s(va_list *list, t_op *op)
{
	char	*str;

	str = va_arg(*list, char*);
	if (op->left == 1)
		pf_ft_lepf_ft_s(op, str);
	else
		pf_ft_rigth_s(op, str);
}
