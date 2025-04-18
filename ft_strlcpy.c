/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:39:06 by restevez          #+#    #+#             */
/*   Updated: 2024/11/28 19:53:28 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_strlcpy(destination, source, size):
DESCRIPTION
The  strlcpy()  and  strlcat()  functions  copy and concatenate strings
respectively.  They are designed to be safer, more consistent, and less
error prone replacements for strncpy(3) and strncat(3).  Unlike  those  
functions,  strlcpy()  and  strlcat() take the full size of the buffer 
(not just the length) and guarantee to NULterminate the result (as long 
as size is larger than 0 or, in the case of strlcat(), as long as  there
is  at least  one  byte  free  in  dst).   Note  that  a byte for the NUL 
should be included in size.  Also note that strlcpy() and strlcat() only
operate on true “C” strings.  This means that for strlcpy() src must be
NUL-terminated and for strlcat() both src and dst must be NUL-terminated.

The  strlcpy() function copies up to size - 1 characters from the 
NUL-terminated string src to dst, NUL-terminating the result.

The strlcat() function appends the NUL-terminated string src to the end
of dst. It will append at most size - strlen(dst) - 1 bytes, 
NUL-terminating the result.

RETURN VALUES
The strlcpy() and strlcat() functions return the total length  of  the
string  they  tried  to  create. For strlcpy() that means the length 
of src.  For strlcat() that means the initial length of dst plus the 
length of src.

While this may seem somewhat confusing, it was done to
make truncation detection simple. Note,  however, that if strlcat()
traverses size characters without finding a NUL, the length of the
string is considered to be size and the destination string will
not be NUL-terminated (since there was no space for the NUL).

This  keeps strlcat() from running off the end of a string.
In practice this should not happen (as it means that either size 
is incorrect or that dst is not a proper “C” string). 
The check exists to prevent  potential security problems in incorrect code.
*/
/*
#include <stdio.h>

int	main(void)
{
	char			dest[10];
	char			*src;
	unsigned int	size;

	size = 11;
	src = "Hello World";
	printf("Return: %u\n", ft_strlcpy(dest, src, size));
	printf("Dest: %s\n", dest);
	return (0);
}
*/
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
