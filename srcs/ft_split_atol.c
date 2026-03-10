
#include <stdlib.h>
#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int	i;
	long	main_number;
	int	flag;

	i = 0;
	main_number = 0;
	flag = 1;
	while ((nptr[i] == ' ') || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if ((nptr[i] == 43) || (nptr[i] == 45))
	{
		if (nptr[i] == 45)
			flag *= -1;
		i++;
	}
	while (nptr[i] <= 57 && nptr[i] >= 48)
	{
		main_number = main_number * 10 + nptr[i] - '0';
		i++;
	}
	return (main_number * flag);
}

static void	to_make_free(char **s_copy, int k)
{
	while (k > 0)
	{
		free(s_copy[k - 1]);
		k--;
	}
}

static int	ft_count(const char *s, char c)
{
	int	flag;
	int	i;
	int	count;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			if (flag == 0)
				count++;
			flag = 1;
			i++;
		}
		flag = 0;
	}
	return (count);
}

static char	**str_process(char **s_copy, char const *s, char c)
{
	int	k;
	int	j;
	int	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		s_copy[k] = ft_substr(s, i, j - i);
		if (!s_copy[k])
		{
			to_make_free(s_copy, k);
			return (NULL);
		}
		i = j;
		k++;
	}
	return (s_copy);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**s_copy;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_count(s, c);
	s_copy = malloc(sizeof(char *) * (word_count + 1));
	if (!s_copy)
		return (NULL);
	while (i <= word_count)
	{
		s_copy[i] = NULL;
		i++;
	}
	if (!str_process(s_copy, s, c))
		return (NULL);
	return (s_copy);
}