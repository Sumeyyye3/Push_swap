/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:56:48 by mozay             #+#    #+#             */
/*   Updated: 2026/01/08 12:21:06 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;
	size_t			i;

	i = 0;
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dest);
}
