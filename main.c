/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:08:38 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 15:08:43 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_validate_sequence(stack** root_a)
{
	stack* curr;

	curr = (*root_a);
	while (curr->next != NULL)
	{
		if (curr->num > curr->next->num)
			return (FALSE);
		curr = curr->next;
	}
	ft_dealloc(root_a);
	return (TRUE);
}

void ft_validate_repeated_numbers(stack **root_a)
{
	stack* icurr;
	stack* jcurr;
	
	icurr = (*root_a);
	while (icurr->next != NULL)
	{
		jcurr = icurr->next;
		while (jcurr != NULL)
		{
			if (icurr->num == jcurr->num)
			{
				ft_dealloc(root_a);
				ft_print_error();
			}
			else
				jcurr = jcurr->next;
		}
		icurr = icurr->next;
	}
}

void ft_validation_valide_char(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (argv[i] != NULL && i < argc)
	{
		if (((*argv[i]) >= '0' && (*argv[i]) <= '9') || ((*argv[i]) == '-' && argv[i][1] != '\0') || ((*argv[i]) == '+' && argv[i][1] != '\0'))
			{
				while ((argv[i][j]) != '\0')
					{
						if ((argv[i][j]) >= '0' && (argv[i][j]) <= '9')
							j++;
						else
						ft_print_error();
					}
				j = 1;
				i++;
			}
		else
		ft_print_error();
	}
}

int main(int argc,char* argv[])
{
	stack* stack_a;
	stack* stack_b;
	// stack* curr;
	int	i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_validation_valide_char(argc, argv);
	while (argv[i] != NULL && i < argc)
	{
		ft_lstadd_back(&stack_a, ft_atoi(argv[i], &stack_a));
		i++;
	}
	ft_validate_repeated_numbers(&stack_a);
	if (ft_validate_sequence(&stack_a))
		return (0);
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
	ft_dealloc(&stack_a);
	ft_dealloc(&stack_b); //Remove when finished since stack_b will be cleaned
	return (0);
}