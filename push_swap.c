/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:39 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/06 00:38:06 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct t_stack {
	int	*num;
} stack;

void init_stack(stack *a, int argc, char *argv[])
{
	int	i;

	i = 0;
	a->num = (int*)malloc(sizeof(int) * (argc - 1));
	// b->num = (int*)malloc(sizeof(int) * (argc - 1));
	while (i < (argc - 1))
	{
		a->num[i] = atoi(argv[i + 1]);
		i++;
	}
	// i = 0;
	// while (i < (argc - 1))
	// {
	// 	printf("arg: %d\n", a->num[i]);
	// 	i++;	
	// }
}

int main(int argc,char *argv[])
{
	stack a;
	stack b;

	init_stack(&a, argc, argv);
	free(a.num);
	// free(b.num);
	return (0);
}
