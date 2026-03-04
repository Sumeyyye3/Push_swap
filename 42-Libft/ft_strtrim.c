/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-29 16:52:59 by mozay             #+#    #+#             */
/*   Updated: 2026-01-29 16:52:59 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	i;
	size_t	start;
	size_t	last;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	last = ft_strlen(s1);
	while (ft_strchr(set, s1[last - 1]) && last > start)
		last--;
	newstr = (char *) malloc (sizeof(char) * (last - start + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (start < last)
		newstr[i++] = s1[start++];
	newstr[i] = '\0';
	return (newstr);
}
