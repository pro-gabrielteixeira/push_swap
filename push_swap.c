/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:39 by gateixei          #+#    #+#             */
/*   Updated: 2023/01/31 17:53:35 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_large(stack** root_a, stack** root_b, int size)
{
	int	pivot;
	int	count;
	
	count = 0;
	pivot = ft_pivot(root_a);
	while ((*root_a)->next != NULL && count < size)
	{
		if((*root_a)->num <= pivot)
			rule_push_b(root_a, root_b);
		else if ((*root_a)->num > (*root_a)->next->num)
			rule_swap_a(root_a);
		else
			rule_reverse_a(root_a);
		count++;
	}
}

void sort_medium(stack** root_a, stack** root_b, int size)
{
	stack*	small_num;
	int		count;

	count = 0;
	small_num = NULL;
	ft_get_small(&small_num, root_a, root_b, size/5);
	while ((*root_a)->next != NULL && count < size)
	{
		if(!(ft_check_small(&small_num, (*root_a)->num)))
			rule_push_b(root_a, root_b);
		else if ((*root_a)->num > (*root_a)->next->num)
		{
			rule_swap_a(root_a);
			count--;
		}
		else
			rule_reverse_a(root_a);
		count++;
	}	
	ft_dealloc(&small_num);
}

void sort_small(stack** root_a, stack** root_b, int size)
{
	int		count;

	count = 0;
	while (count < (size/2))
	{
		if ((*root_a)->num == get_max(root_a) || (*root_a)->num == get_min(root_a))
		{
			sort_stack_small_b(root_a, root_b);
			count++;
		}
		else
			rule_shift_a(root_a);
	}
	while ((*root_b) != NULL)
	{
		rule_push_a(root_a, root_b);
		sort_stack_small_a(root_a);
	}
}

void init_sort(stack** root_a, stack** root_b)
{
	stack* curr;
	int	i;

	i = 0;
	curr = *root_a;
	while ((curr) != NULL)
	{
		curr = curr->next;
		i++;
	}
	if (i <= 3)
		sort_stack_small_a(root_a);
	else if (i <= 5)
		sort_small(root_a, root_b, i); 
	else if (i <= 99)
		sort_medium(root_a, root_b, i);
	else
		sort_large(root_a, root_b, i);
}
