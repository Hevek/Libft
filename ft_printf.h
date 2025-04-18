/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:22:08 by restevez          #+#    #+#             */
/*   Updated: 2025/01/12 06:06:44 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

int		ft_printf(const char *str, ...);
size_t	ft_printf_s(va_list **args);
size_t	ft_printf_id(char **str, va_list **args);
size_t	ft_printf_p(va_list **args);
size_t	ft_printf_x(va_list **args, char *base);
size_t	ft_printf_u(va_list **args);
size_t	ft_put_hex(size_t nbr, size_t *chr_count);
size_t	ft_putnbr_base(unsigned int nbr, char *base, size_t *chr_count);

#endif
