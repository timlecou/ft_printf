/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:40:18 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/05 16:31:29 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef	struct	s_op
{
	int		width;
	int		prec;
	int		left;
	char	conv;
	int		char_nb;
	int		is_prec;
	int		is_zero;
}				t_op;

int				pf_ft_len(char *str);
int				ft_printf(const char *str, ...);
t_op			pf_ft_init_op(void);
t_op			pf_ft_fill_op(char *format, va_list *list);
char			*pf_ft_get_string(char *str);
char			pf_ft_get_char(int nb, int num);
int				pf_ft_is_flag(char c);
int				pf_ft_skip_nb(char *str);
int				pf_ft_s_int(int nb, t_op *op);
int				pf_ft_s_u(unsigned int nb, t_op *op);
int				pf_ft_size_uintptr_t(uintptr_t nb);
void			print_conversion(va_list *list, t_op *op);
void			pf_ft_print_d(va_list *list, t_op *op);
void			pf_ft_print_c(va_list *list, t_op *op);
void			pf_ft_print_x(va_list *list, t_op *op, int nb);
int				pf_ft_op_size(char *str, t_op *op);
void			pf_ft_print_s(va_list *list, t_op *op);
void			pf_ft_print_u(va_list *list, t_op *op);
void			pf_ft_print_per(t_op *op);
void			pf_ft_print_p(va_list *list, t_op *op);
int				pf_ft_set(t_op *op, int n, char c);
void			pf_ft_putnbr_fd_u(t_op *op, unsigned int nb, int fd);
char			*pf_ft_itoa_u(unsigned int nb, t_op *op);
char			*pf_ft_itoa_base_p(uintptr_t nb, int num);
char			*pf_ft_itoa_base_x(unsigned int nb, int num);
int				pf_ft_is_in_str(char c, char *str);
void			pf_ft_write(t_op *op, int fd, char *str, int l);
int				pf_ft_get_size_p(uintptr_t ptr);
int				pf_ft_get_size_x(unsigned long long nb);
void			pf_ft_last_change(t_op *op);
int				pf_ft_rigth_d2(t_op *op, intmax_t nb);
int				pf_ft_left_d2(t_op *op, intmax_t nb);
char			*pf_ft_itoa_d(int nb);
#endif
