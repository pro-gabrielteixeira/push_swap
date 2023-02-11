/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:36:25 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 16:11:39 by gateixei         ###   ########.fr       */
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
    if ((ft_check_small(small_sort, (*root_b)->num)))
    {
        if ((*root_b)->next != NULL)
            rule_shift_b(root_b);
        count++;
    }
    return (count);
}

int swap_sorting(stack** root)
{
    stack* curr;
    int i;
    int j;
    
    i = get_max(root);
    j = 0;
    curr = (*root);
    while (curr->num != i)
    {
        j++;
        curr = curr->next;
    }
    if (j > (get_size(root)/2))
        return (FALSE);
    else
        return (TRUE);
}

void sorting_medium_a(stack** root_a, stack** root_b)
{
    while ((*root_b))
    {
        if ((*root_b)->num == get_max(root_b))
            rule_push_a(root_a, root_b);
        else if (swap_sorting(root_b))
        {
            while ((*root_b)->num != get_max(root_b))
                rule_shift_b(root_b);
            rule_push_a(root_a, root_b);
        }
        else
        {
            while ((*root_b)->num != get_max(root_b))
                rule_reverse_b(root_b);
            rule_push_a(root_a, root_b);
        }
    }
}
