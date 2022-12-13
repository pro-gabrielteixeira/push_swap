/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:39 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/13 21:01:29 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void compare_stack_b(stack** root_b)
{
	stack* curr_b;
	int		last_num;
	int		first;
	int		sec;
	
	
	curr_b = *root_b;
	if (curr_b->next == NULL)
		return;
	last_num = lstlast(root_b);
	first = curr_b->num;
	sec = curr_b->next->num;
	if (first > sec && first > last_num && sec < last_num)
	{
		rule_reverse_b(root_b);
		rule_swap_b(root_b);
	}
	else if (first > sec && first < last_num && sec < last_num)
		rule_reverse_b(root_b);
	else if (first < sec && first > last_num && sec > last_num)
		rule_swap_b(root_b);
	else if (first < sec && first < last_num && sec > last_num)
	{
		rule_reverse_b(root_b);
		rule_swap_b(root_b);
		rule_shift_b(root_b);
		rule_swap_b(root_b);
	}
	else if (first < sec && first < last_num && sec < last_num)
	{
		rule_swap_b(root_b);
		rule_reverse_b(root_b);
	}
	printf("(Inside compare_stack) Stack B: %d\n", curr_b->num);	
}

void condition_sort(stack** root_a, stack** root_b)
{
	stack* curr_a;
	int	pivot;

	curr_a = *root_a;
	if ((*root_a))
		pivot = lstlast(root_a);
	while (curr_a->num != pivot)
	{
		if (curr_a->num > pivot)
			rule_shift_a(root_a);
		else
		{
			rule_push_b(root_a, root_b);
			compare_stack_b(root_b);
		}
		// curr_a = *root_a;
		printf("(Inside While) Stack A: %d\n", curr_a->num);
	}
	rule_push_b(root_a, root_b);
	if (curr_a->next != NULL)
	{
		printf("(Inside Rec) Stack A: %d\n", curr_a->num);
		condition_sort(root_a, root_b);
	}
}

void init_sort(stack** root_a, stack** root_b)
{
	stack* curr;

	curr = *root_a;
	// while (curr->next != NULL)
	// {
		// printf("(Inside While) Stack A: %d\n", curr->num);
	// 	if (curr->num < curr->next->num)
	// 		curr = curr->next;
	// 	else {
			condition_sort(root_a, root_b);
			// curr = *root_a;
	// 	}
	// }
}

int main(int argc,char* argv[])
{
	stack* stack_a;
	stack* stack_b;
	stack* curr;
	int	i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (argv[i] != NULL && i < argc)
	{
		ft_lstadd_back(&stack_a, atoi(argv[i]));
		i++;
	}
	init_sort(&stack_a, &stack_b);
	curr = stack_a;
	while (curr)
	{
		printf("(Final) Stack A: %d\n", curr->num);
		curr = curr->next;
	}
	// curr = stack_b;
	// while (curr)
	// {
	// 	printf("(Final) Stack B: %d\n", curr->num);
	// 	curr = curr->next;
	// }
	// ft_dealloc(stack_a);
	ft_dealloc(stack_b); //Remove when finished since stack_b will be cleaned
	return (0);
}