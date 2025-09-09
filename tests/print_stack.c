#include "../incs/testing.h"

void	set_mov(t_stack *a)
{
	t_stack	*temp;
	int		i;
	int		size;

	if (!a)
		exit(1);// HACK:
	temp = a;
	size = ft_stack_size(a);
	i = 0;
	while (temp)
	{
		if (i <= size / 2)
			temp->cost = i;
		else
			temp->cost = i - size;
		temp = temp->next;
		i++;
	}
}

void	mini_print_stacks(t_stack **a, t_stack **b)
{
	t_stack	*ta;
	t_stack	*tb;

	ta = *a;
	tb = *b;
	set_mov(*a);
	ft_printf("\t  A\t\t\t  B\n");
	ft_printf("\t------\t\t\t------\n");
	while (ta || tb){
		if (ta){
			ft_printf("\t %d m[%d] c[%d]\t", ta->index, ta->cost, ta->chunkid);
			ta = ta->next;
		}	
		else
			ft_printf("\t\t\t");
		if (tb){
			ft_printf("\t %d m[%d] c[%d]", tb->index, tb->cost, tb->chunkid);
			tb = tb->next;
		}
		ft_printf("\n");
	}
}

void	print_stack(t_stack **st)
{
	int		i;
	t_stack	*tmp;

	if (!st) // || !*st)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	i = 0;
	tmp = *st;
	while (tmp)
	{
		//value -> %d\n // before index
		//ft_printf("address -> %p\n", tmp);
		ft_printf("node[%d]:\nvalue -> %d\nindex -> %d\nin chunk -> %d\n", i, tmp->value, tmp->index, tmp->chunkid);
		i++;
		tmp = tmp->next;
		if (tmp)
			ft_printf("\n");
	}
}

void	test_movements(t_stack	**pa)
{
	t_stack	**pb;

	// pa = pa;
	pb = NULL;
	
	// NORMAL STACK
	ft_printf("\n-*-*-*-*-*-*-\n==> Before Movements:\n\n-< Stack A >-\n");
	print_stack(pa);
	ft_printf("\n\n-< Stack B >-\n");
	print_stack(pb);
	
	// SWAP A
	ft_printf("-*-*-*-*-*-*-\n\n-*-*-<sa>-*-*-\n==> After SwapA:\n");
	ft_stack_swap(pa, 0);
	ft_printf("\n-< Stack A >-\n");
	print_stack(pa);

	// ROTATE A (1st goes last)
	ft_printf("\n\n-*-*-<ra>-*-*-\n==> After Rotate A (1st goes last):\n");
	ft_stack_rotate(pa, 0);
	ft_printf("\n-< Stack A >-\n");
	print_stack(pa);
	ft_printf("\n-*-*-<ra>-*-*-\n");
	
	//REVERSE ROTATE A (last goes 1st)
	ft_printf("\n-*-*-<rra>-*-*-\n==> After Reverse Rotate A (last goes 1st):\n");
	ft_stack_revrotate(pa, 0);
	ft_printf("\n-< Stack A >-\n");
	print_stack(pa);
	ft_printf("\n-*-*-<ra>-*-*-\n");

	// PUSH A (b -> a)
	ft_printf("\n-*-*-<sa>-*-*-\n\n-*-*-<pa>-*-*-\n==> After Push (top of B to) A:\n");
	ft_stack_push(pa, pb, 0);
	ft_printf("\n-< Stack A >-\n");
	print_stack(pa);
	ft_printf("\n\n-< Stack B >-\n");
	print_stack(pb);

	//PUSH B (a -> b)
	ft_printf("-*-*-<pa>-*-*-\n\n-*-*-<pb>-*-*-\n==> After Push (top of A to) B:\n");
	ft_stack_push(pb, pa, 1);
	ft_printf("\n before print_stack: %p, %p", pb, *pb);
	ft_printf("\n-< Stack A >-\n");
	print_stack(pa);
	ft_printf("\n\n-< Stack B >-\n");
	print_stack(pb);
	// NOTE: *pb is changing address after entering print_stack
	//	check valgrind errors, might be related
	ft_printf("\nafter print_stack: %p, %p", pb, *pb);
	ft_printf("\n-*-*-<pb>-*-*-\n");

	//ft_stack_clear(pb);
}
/*
// range will either be stack_size if we want to check the whole stack. or chunk size for chunk sort check
char	ft_checksort(t_stack *s, long *tab, int asc, int range)
{
	t_stack	*tmp;
	int		i;

	//NOTE: figure out if array will be needed; if not then remove from params
	//		i can use the nodes index as array comparison instead of comparing with the next
	(void)tab; 
	tmp = s;
	i = -1;
	if (asc == 1) // check for ascending order
	{
		while (++i < range && tmp->next)
		{
			ft_printf("%d<%d-[i%d] ", tmp->index, tmp->next->index, i);
			if (tmp->index > tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	else if (asc == 0) // check for descending order
	{
		while (++i < range && tmp->next)
		{
			ft_printf("[%d][i%d]", tmp->index, i);
			if (tmp->index < tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	ft_printf("\nrange = %d, i = %d, bool = %d\n", range, i, (i == range - 1));
	return (i);
}
// 1 if we went through the whole range OK, 0 if not (if there was still node in there)
*/
