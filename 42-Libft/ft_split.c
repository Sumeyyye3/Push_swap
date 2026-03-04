/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-30 09:41:45 by mozay             #+#    #+#             */
/*   Updated: 2026-01-30 09:41:45 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free(char **res, size_t count)
{
	while (count > 0)
		free(res[--count]);
	free(res);
}

static char	**ft_allocate(char const *s, char **res, char c)
{
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!res)
		return (NULL);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	res_iter;
	size_t	s_iter;

	res_iter = 0;
	s_iter = 0;
	res = NULL;
	res = ft_allocate(s, res, c);
	while (s[s_iter])
	{
		while (s[s_iter] == c)
			s_iter++;
		if (!s[s_iter])
			break ;
		res[res_iter] = ft_substr(s, s_iter, ft_word_len(s + s_iter, c));
		if (!res[res_iter])
		{
			ft_free(res, res_iter);
			return (NULL);
		}
		s_iter += ft_word_len(s + s_iter, c);
		res_iter++;
	}
	res[res_iter] = NULL;
	return (res);
}
