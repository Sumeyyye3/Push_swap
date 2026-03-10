#include <stdlib.h>
#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static int	s_len(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_empty(void)
{
	char	*empty;

	empty = malloc(1);
	if (!empty)
	{
		return (NULL);
	}
	empty[0] = '\0';
	return (empty);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	j;
	char			*s_copy;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = s_len(s);
	if (start >= j)
		return (ft_empty());
	if (len > j - start)
		len = j - start;
	s_copy = malloc(len + 1);
	if (!s_copy)
		return (NULL);
	while (s[start] && (i < len))
	{
		s_copy[i] = s[start];
		i++;
		start++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}