/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:12:49 by restevez          #+#    #+#             */
/*   Updated: 2025/01/12 06:18:33 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(unsigned int nbr, char *base, size_t *chr_count)
{
	size_t	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	*chr_count += 1;
	if (nbr >= len)
		ft_putnbr_base(nbr / len, base, chr_count);
	write(1, &base[nbr % len], 1);
	return (*chr_count);
}

size_t	ft_printf_s(va_list **args)
{
	char	*str;

	str = va_arg(**args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	ft_printf_id(char **str, va_list **args)
{
	int		nbr;
	size_t	len;

	nbr = va_arg(**args, int);
	*str = ft_itoa(nbr);
	len = ft_strlen(*str);
	ft_putstr_fd(*str, 1);
	free(*str);
	return (len);
}

size_t	ft_printf_u(va_list **args)
{
	size_t	chr_count;

	chr_count = 0;
	return (ft_putnbr_base(va_arg(**args, unsigned int),
			"0123456789", &chr_count));
}
