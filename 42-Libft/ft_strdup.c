/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-09 11:58:48 by mozay             #+#    #+#             */
/*   Updated: 2026-01-09 11:58:48 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dup_str;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dup_str = (char *) malloc ((len + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup_str[i] = src[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
