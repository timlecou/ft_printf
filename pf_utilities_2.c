/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utilities_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 10:58:05 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/04 14:00:24 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_ft_is_flag(char c)
{
	return (c == '0' || c == '-');
}

int		pf_ft_skip_nb(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]) && str[i] != '\0')
		i++;
	return (i);
}

int		pf_ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	pf_ft_last_change(t_op *op)
{
	if (op->prec < 0)
	{
		op->prec = 0;
		op->is_prec = 0;
	}
	if (op->width < 0)
	{
		op->width *= -1;
		op->left = 1;
	}
	if (op->is_zero == 1 && op->left == 1)
		op->is_zero = 0;
}

t_op	pf_ft_init_op(void)
{
	t_op	op;

	op.conv = ' ';
	op.width = 0;
	op.prec = 0;
	op.left = 0;
	op.char_nb = 0;
	op.is_prec = 0;
	op.is_zero = 0;
	return (op);
}
