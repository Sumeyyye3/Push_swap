
int	ft_recursive_power(int nb, float power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
    nb = nb * ft_recursive_power(nb, (power - 1));
	return (nb);
}
static void ft_arrange_numbers(t_stack *stack_b, int block_size)
{
    int i;
    t_stack temp;
    t_stack stack_c;

    i = 0;
    temp = stack_b;
    while(i < block_size && temp != NULL && stack_b != NULL)
    {
        if((stack_b->value) >= (temp->value))
        {
            push_b(temp,stack_c);
            temp = temp->next;
        }
        else
        {
            push_b(stack_b,stack_c);
            stack_b = stack_b->next;
        }
    }
}
t_stack    ft_block_based_sort(t_stack stack_a)
{
    int size;
    int block_size;
    t_stack temp;
    t_stack stack_b;

    size = ft_stack_size(stack_a);
    block_size = ft_recursive_power(size,(0.5));
    temp = stack_a;
    while(stack_a)   
    {                
        size = 0;
        while(size < block_size)
        {
            temp = temp->next;
            size++;
        }
        ft_simple_sort(&stack_a,&stack_b);
        stack_a = temp; 
    }
    ft_arrange_numbers(&stack_b, block_size);
}
