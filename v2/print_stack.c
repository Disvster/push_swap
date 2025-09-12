#include "testing.h"

void	mini_print_stacks(t_stack **a, t_stack **b)
{
	t_stack	*ta;
	t_stack	*tb;

	ta = *a;
	tb = NULL;
	if (b)
		tb = *b;
	ft_printf("\t  A\t\t  B\n");
	ft_printf("\t------\t\t------\n");
	while (ta || tb){
		if (ta)
		{
			ft_printf("\t %d\t", ta->index);//, ta->cost, ta->target->index);
			ta = ta->next;
		}	
		else
			ft_printf("\t\t");
		if (tb){
			ft_printf("\t %d", tb->index);//, tb->cost, tb->target->index);
			tb = tb->next;
		}
		ft_printf("\n");
	}
}
