/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozay <mozay@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:57:49 by mozay             #+#    #+#             */
/*   Updated: 2026/03/07 13:58:34 by mozay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void    push_a(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (!b || !*b)
        return ;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write(1, "pa\n", 3);
}

void    push_b(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (!a || !*a)
        return ;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    write(1, "pb\n", 3);
}

void    rotate_a(t_stack **a)
{
    t_stack *temp;
    t_stack *last;

    if (!a || !*a || !(*a)->next)
        return ;
    
    last = ft_lstlast(*a);
    temp = *a;
    *a = (*a)->next;
    temp->next = NULL;
    last->next = temp;
    write(1, "ra\n", 3);
}

void    rotate_b(t_stack **b)
{
    t_stack *temp;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return ;
    
    last = ft_lstlast(*b);
    temp = *b;
    *b = (*b)->next;
    temp->next = NULL;
    last->next = temp;
    write(1, "rb\n", 3);
}

void    reverse_rotate_a(t_stack **a)
{
    t_stack *prev;
    t_stack *last;

    if (!a || !*a || !(*a)->next)
        return ;
    
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
}

void   reverse_rotate_b(t_stack **b)
{
    t_stack *prev;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return ;
    
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
}