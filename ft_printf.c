/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:46:00 by restevez          #+#    #+#             */
/*   Updated: 2025/04/18 20:37:22 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(const char *str, ...);
static int	ft_flag_selector(char flag, va_list *args);

/* ft_printf(str, infinite):
Flag characters

The character % is followed by zero or more of the following flags:

\#	The value should be converted to an "alternate form".
For  o  conversions,  the  first character  of  the  output
string is made zero (by prefixing a 0 if it was not zero already).
For x and X conversions, a nonzero result has the string "0x"
(or "0X"  for  X conversions)  prepended  to it.
For a, A, e, E, f, F, g, and G conversions, the result will always
contain a decimal point, even if no digits follow it (normally, a
decimal point  appears in the results of those conversions only if
a digit follows).  For g and G conversions, trailing zeros are not
removed from the result as they  would  otherwise be. For other
conversions, the result is undefined.

0	The value should be zero padded.  For d, i, o, u, x, X, a, A,
e, E, f, F, g, and G conversions, the converted value is padded on
the left with zeros rather than blanks. If the  0  and - flags both
appear, the 0 flag is ignored.  If a precision is given with a numeric
conversion (d, i, o, u, x, and X), the 0 flag is ignored. For other
conversions, the behavior is undefined.

\-	The  converted  value  is  to  be left adjusted on the field boundary.
(The default is right justification.)  The converted value is padded
on the right with  blanks,  rather than on the left with blanks or zeros.
A - overrides a 0 if both are given.

' '	(a space) A blank should be left before a positive number (or empty
string) produced by a signed conversion.

\+	A sign (+ or -) should always be placed before a number produced by
a  signed  conversion. By default, a sign is used only for negative numbers.
A + overrides a space if both are used.
*/
int	ft_printf(const char *str, ...)
{
	static int	count_char;
	int			i;
	va_list		args;

	if (!str)
		return (-1);
	i = -1;
	va_start(args, str);
	count_char = 0;
	while (str[++i])
	{
		if (str[i + 1] == '\0' && ++count_char)
			ft_putchar_fd(str[i], 1);
		else if (str[i] == '%')
			count_char += ft_flag_selector(str[++i], &args);
		else
		{
			ft_putchar_fd(str[i], 1);
			count_char++;
		}
	}
	va_end(args);
	return (count_char);
}

static int	ft_flag_selector(char flag, va_list *args)
{
	char	*str;

	if (!ft_strchr("cspdiuxX%", flag))
		flag = '%';
	if (flag == 's')
		return (ft_printf_s(&args));
	else if (flag == 'i' || flag == 'd')
		return (ft_printf_id(&str, &args));
	else if (flag == 'c')
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (flag == '%')
		ft_putchar_fd('%', 1);
	else if (flag == 'p')
		return (ft_printf_p(&args));
	else if (flag == 'u')
		return (ft_printf_u(&args));
	else if (flag == 'x')
		return (ft_printf_x(&args, "0123456789abcdef"));
	else if (flag == 'X')
		return (ft_printf_x(&args, "0123456789ABCDEF"));
	return (1);
}
