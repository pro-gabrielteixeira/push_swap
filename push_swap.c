/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:39 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/05 23:40:16 by gateixei         ###   ########.fr       */
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
	stack*	small_sort;
	int		count;
	int		i;

	small_num = NULL;
	small_sort = NULL;
	ft_get_small(&small_num, root_a, size);
	count = 0;
	i = get_size(&small_num);
	ft_get_small(&small_sort, &small_num, count);
	while ((*root_a)->next != NULL && i && get_size(root_a) > 3)
	{
		if(!(ft_check_small(&small_num, (*root_a)->num)))
		{
			count = sorting_medium_b(root_a, root_b, &small_sort, count);
			i--;
		}
		else
			rule_shift_a(root_a);
	}
	while (count--)
		rule_reverse_b(root_b);
	ft_dealloc(&small_num);
	ft_dealloc(&small_sort);
	if (get_size(root_a) > 3)
		sort_medium(root_a, root_b, size);
	else
	{
		sort_stack_small_a(root_a);
		sorting_medium_a(root_a, root_b);
	}
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
	int	i;

	i = get_size(root_a);
	if (i <= 3)
		sort_stack_small_a(root_a);
	else if (i <= 5)
		sort_small(root_a, root_b, i); 
	else if (i <= 99)
		sort_medium(root_a, root_b, i/5);
	else
		sort_large(root_a, root_b, i);
}
