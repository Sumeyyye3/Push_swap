#include "push_swap.h"


int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**numbers;
	int		i;

	if (ac < 2)
		return (0);
	
	// Argümanları kontrol et (ft_split kullanarak)
	if (!check_arguments(ac, av))
		return (1);
	
	// Stack'i oluştur (ft_lstnew ve ft_lstadd_back kullanarak)
	stack_a = NULL;
	stack_b = NULL;
	
	// Argümanları stack'e ekle
	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	else
		numbers = av + 1;
	
	i = 0;
	while (numbers[i])
	{
		t_list *new = ft_lstnew(ft_atoi(numbers[i]));
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	
	// Belleği temizle (ft_lstclear kullanarak)
	if (ac == 2)
		ft_free(numbers);
	
	// Sıralama yap...
	
	ft_lstclear(&stack_a,free);
	ft_lstclear(&stack_b, free);
	return (0);
}