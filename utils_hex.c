/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:22:54 by restevez          #+#    #+#             */
/*   Updated: 2025/01/11 04:53:12 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_hex(size_t nbr, size_t *chr_count)
{
	*chr_count += 1;
	if (nbr >= 16)
		ft_put_hex(nbr / 16, chr_count);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (*chr_count);
}

size_t	ft_printf_p(va_list **args)
{
	size_t	chr_count;
	size_t	ptr;

	ptr = va_arg(**args, size_t);
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		chr_count = 5;
		return (chr_count);
	}
	chr_count = 2;
	ft_putstr_fd("0x", 1);
	return (ft_put_hex(ptr, &chr_count));
}

size_t	ft_printf_x(va_list **args, char *base)
{
	size_t	chr_count;

	chr_count = 0;
	return (ft_putnbr_base(va_arg(**args, unsigned int),
			base, &chr_count));
}
