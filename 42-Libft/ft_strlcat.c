/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:57:23 by mozay             #+#    #+#             */
/*   Updated: 2026/01/07 18:57:25 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	result;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	result = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size > dest_len)
		result = dest_len + src_len;
	else
		result = src_len + size;
	while (src[i] && (dest_len + 1 < size))
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return (result);
}
