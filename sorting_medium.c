/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:36:25 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/01 21:17:50 by gateixei         ###   ########.fr       */
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

void sorting_medium_b(stack** root_a, stack** root_b, stack** small_sort)
{
    rule_push_b(root_a, root_b);
    if ((*root_b)->next == NULL)
        return ;
    if (!(ft_check_small(small_sort, (*root_b)->num)))
        rule_shift_b(root_b);
}