/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:30:00 by mozay             #+#    #+#             */
/*   Updated: 2026/03/13 00:21:53 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*s_copy;

	i = 0;
	j = 0;
	while (s[i])
	{
		i++;
	}
	s_copy = malloc(i + 1);
	if (!s_copy)
	{
		return (NULL);
	}
	while (s[j])
	{
		s_copy[j] = s[j];
		j++;
	}
	s_copy[j] = '\0';
	return (s_copy);
}
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str_c;
	size_t			i;

	i = 0;
	str_c = (unsigned char *)s;
	while (i < n)
	{
		str_c[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
