/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:57:49 by mozay             #+#    #+#             */
/*   Updated: 2026/03/05 21:38:31 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    push_a(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (!b || !*b)
        return (-1);
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write(1, "pa\n", 3);
    return (0);
}

int    push_b(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (!a || !*a)
        return (-1);
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    write(1, "pb\n", 3);
    return (0);
}

int    rotate_a(t_stack **a)
{
    t_stack *temp;
    t_stack *last;

    if (!a || !*a || !(*a)->next)
        return (-1);
    
    last = ft_lstlast(*a);
    temp = *a;
    *a = (*a)->next;
    temp->next = NULL;
    last->next = temp;
    write(1, "ra\n", 3);
    return (0);
}

int    rotate_b(t_stack **b)
{
    t_stack *temp;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return (-1);
    
    last = ft_lstlast(*b);
    temp = *b;
    *b = (*b)->next;
    temp->next = NULL;
    last->next = temp;
    write(1, "rb\n", 3);
    return (0);
}

int    reverse_rotate_a(t_stack **a)
{
    t_stack *prev;
    t_stack *last;

    if (!a || !*a || !(*a)->next)
        return (-1);
    
    prev = NULL;
    last = *a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *a;
    *a = last;
    write(1, "rra\n", 4);
    return (0);
}

int    reverse_rotate_b(t_stack **b)
{
    t_stack *prev;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return (-1);
    
    prev = NULL;
    last = *b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = *b;
    *b = last;
    write(1, "rrb\n", 4);
    return (0);
}