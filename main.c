/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:08:38 by gateixei          #+#    #+#             */
/*   Updated: 2023/01/06 23:33:11 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc,char* argv[])
{
	stack* stack_a;
	stack* stack_b;
	// stack* curr;
	int	i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (argv[i] != NULL && i < argc)
	{
		ft_lstadd_back(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	init_sort(&stack_a, &stack_b);
	// curr = stack_a;
	// while (curr)
	// {
	// 	printf("(Final) Stack A: %d\n", curr->num);
	// 	curr = curr->next;
	// }
	// curr = stack_b;
	// while (curr)
	// {
	// 	printf("(Final) Stack B: %d\n", curr->num);
	// 	curr = curr->next;
	// }
	ft_dealloc(stack_a);
	// ft_dealloc(stack_b); //Remove when finished since stack_b will be cleaned
	return (0);
}