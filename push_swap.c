/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:39 by gateixei          #+#    #+#             */
/*   Updated: 2023/01/06 23:32:20 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_large(stack** root_a, stack** root_b)
{
	stack*	curr;
	
	curr = *root_a;
	while (curr)
	{
		printf("(Large) Stack A: %d\n", curr->num);
		curr = curr->next;
	}
	curr = *root_b;
	while (curr)
	{
		printf("(Large) Stack B: %d\n", curr->num);
		curr = curr->next;
	}
}

void sort_medium(stack** root_a, stack** root_b)
{
	stack*	curr;
	
	curr = *root_a;
	while (curr)
	{
		printf("(Medium) Stack A: %d\n", curr->num);
		curr = curr->next;
	}
	curr = *root_b;
	while (curr)
	{
		printf("(Medium) Stack B: %d\n", curr->num);
		curr = curr->next;
	}
}

void sort_small(stack** root_a, stack** root_b, int size)
{
	// stack*	curr;
	int		count;

	count = 0;
	// curr = *root_a;
	while (count < (size/2))
	{
		if ((*root_a)->num == get_min(root_a)) // (*root_a)->num == get_max(root_a) ||
		{
			sort_stack_small_b(root_a, root_b);
			count++;
			// curr = (*root_a);
			// while (curr)
			// {
			// 	printf("(sort_small) Stack A: %d\n", curr->num);
			// 	curr = curr->next;
			// }
		}
		else
			rule_shift_a(root_a);
	}
	while ((*root_b) != NULL)
		sort_stack_small_a(root_a, root_b);
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
	if (i <= 5)
		sort_small(root_a, root_b, i);
	else if (i <= 249)
		sort_medium(root_a, root_b);
	else
		sort_large(root_a, root_a);
}
