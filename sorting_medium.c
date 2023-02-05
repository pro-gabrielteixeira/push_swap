/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:36:25 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/05 22:36:02 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int ft_check_small(stack** small, int i)
{
    stack* curr;
    
    curr = (*small);
    while (curr)
    {
        if (curr->num == i) 
            return FALSE;
        curr = curr->next;
    }
    return TRUE;
}

void get_min_stack(stack** small, stack** root)
{
    stack* curr;
    int i;

    curr = (*root);
    i = get_max(root);
    while (curr)
    {
        if(i > curr->num && ft_check_small(small, curr->num))
            i = curr->num;
        curr = curr->next;
    }
    ft_lstadd_back(small, i);
}

void ft_get_small(stack** small, stack** root, int size)
{
    while (size--)
        get_min_stack(small, root);
}

int sorting_medium_b(stack** root_a, stack** root_b, stack** small_sort, int count)
{
    rule_push_b(root_a, root_b);
    if ((*root_b)->next == NULL)
        return (count);
    if ((ft_check_small(small_sort, (*root_b)->num)))
    {
        rule_shift_b(root_b);
        count++;
    }
    return (count);
}

void sorting_medium_a(stack** root_a, stack** root_b)
{
	while ((*root_b))
	{
        if ((*root_b)->next != NULL && (*root_a)->next != NULL)
        {
            if (((*root_a)->num > (*root_a)->next->num) && ((*root_b)->num < (*root_b)->next->num))
                rule_swap_ss(root_a, root_b);
            else if ((*root_b)->num < (*root_b)->next->num)
                rule_swap_b(root_b);
            else if ((*root_a)->num > (*root_a)->next->num)
                rule_swap_a(root_a);
            if ((*root_a)->num < (*root_b)->num)
            {
                rule_push_b(root_a, root_b);
                rule_swap_b(root_b);
            }
        }
    rule_push_a(root_a, root_b);
    }
}