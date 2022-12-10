/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:39 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/10 04:21:59 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	rule_push_a(&stack_a, &stack_b);
	rule_push_b(&stack_a, &stack_b);
	rule_push_b(&stack_a, &stack_b);
	rule_push_b(&stack_a, &stack_b);
	rule_push_a(&stack_a, &stack_b);
	rule_shift_a(&stack_a);
	rule_shift_b(&stack_b);
	rule_shift_rr(&stack_a, &stack_b);
	rule_reverse_a(&stack_a);
	rule_reverse_b(&stack_b);
	rule_reverse_rrr(&stack_a, &stack_b);
	rule_reverse_rrr(&stack_a, &stack_b);
	curr = stack_a;
	while (curr)
	{
		printf("Stack A: %d\n", curr->num);
		curr = curr->next;
	}
	curr = stack_b;
	while (curr)
	{
		printf("Stack B: %d\n", curr->num);
		curr = curr->next;
	}
	ft_dealloc(stack_a);
	ft_dealloc(stack_b);
	return (0);
}