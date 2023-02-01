/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:47:43 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/01 19:33:01 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min(stack** root)
{
    stack* curr;
    int i;

    curr = (*root);
    i = curr->num;
    while (curr)
    {
        if(i > curr->num)
            i = curr->num;
        curr = curr->next;
    }
    return (i);
}

int get_max(stack** root)
{
    stack* curr;
    int i;

    curr = *root;
    i = curr->num;
    while (curr)
    {
        if(i < curr->num)
            i = curr->num;
        curr = curr->next;
    }
    return (i);
}

void ft_print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int ft_pivot(stack** root)
{
    long int    result;
    unsigned int i;
    stack* curr;

    i = 0;
    result = 0;
    curr = (*root);
    while (curr != NULL)
    {
        result += curr->num;
        curr = curr->next;
        i++;
    }
    return ((int)result/i);
}

int get_size(stack** root)
{
	stack* curr;
	int	i;

	i = 0;
	curr = *root;
	while ((curr) != NULL)
	{
		curr = curr->next;
		i++;
	}
    return (i);
}