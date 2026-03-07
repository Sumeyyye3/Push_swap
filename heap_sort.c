#include "includes/push_swap.h"

void    ft_top_stack(t_stack *stack_a, int max_index)
{
    int size ;

    size = ft_stack_size(stack_a);

    if(max_index < (size / 2))
        rotate_a(&stack_a);
    else
        reverse_rotate_a(&stack_a);
}

t_stack *heap_sort(t_stack *stack_a)
{
    int max_value;
    int max_index;
    int flag;
    t_stack *stack_b;

    while(stack_a)
    {
        max_value = get_max_value(stack_a);
        max_index = get_position(stack_a);
        ft_top_stack(&stack_a, max_index);
        push_b(&stack_a, &stack_b);
    }
    return (stack_b);
}