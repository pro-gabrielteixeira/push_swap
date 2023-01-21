/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:56:50 by gateixei          #+#    #+#             */
/*   Updated: 2023/01/20 03:18:22 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stack_small_b(stack** root_a, stack** root_b)
{
    int first;
    int sec;
    int last;
    
    rule_push_b(root_a, root_b);
    if ((*root_b)->next == NULL || (*root_a)->next == NULL)
        return ;
    first = (*root_a)->num;
    sec = (*root_a)->next->num;
    last = lstlast(root_a);
    if (first != get_min(root_a))
    {
        if (last == get_min(root_a))
            rule_reverse_a(root_a);
        else if (sec == get_max(root_a))
            rule_swap_a(root_a);  
    }
}

void sort_stack_small_a(stack** root_a, stack** root_b)
{
    int first;
    int sec;
    int last;
    
    if ((*root_a)->next == NULL)
        return ;
    first = (*root_a)->num;
    sec = (*root_a)->next->num;
    last = lstlast(root_a);
    if (first < sec && first < last && sec > last)
    {
        rule_swap_a(root_a);
        rule_shift_a(root_a);
    }
    else if (first > last && first > sec)
    {
        rule_swap_a(root_a);
        rule_reverse_a(root_a);
    }
    else if (first > sec)
        rule_swap_a(root_a);
    rule_push_a(root_a, root_b);
    if ((*root_a)->num > first)
        rule_shift_a(root_a);
}

/*
void sort_stack_small_b(stack** root_a, stack** root_b)
{
    int first;
    int sec;
    int last;
    
    rule_push_b(root_a, root_b);
    if ((*root_b)->next == NULL)
        return ;
    first = (*root_b)->num;
    sec = (*root_b)->next->num;
    last = lstlast(root_b);
    if ((*root_a)->num != get_max(root_a) && (*root_a)->num != get_min(root_a))
    {
        if (first < sec && first > last)
            rule_swap_b(root_b);
        else if (first < sec && first < last)
        {
            rule_reverse_b(root_b);
            rule_swap_b(root_b);
            rule_shift_rr(root_a, root_b);
        }
        else if (first > sec && first < last)
            rule_reverse_b(root_b);
    }
    else
    {
        if (first < sec && first > last)
            rule_swap_b(root_b);
        else if (first < sec && first < last && sec < last)
        {
            rule_reverse_b(root_b);
            rule_swap_b(root_b);
            rule_shift_b(root_b);
        }
        else if (first < sec && first < last && sec > last)
        {
            rule_reverse_b(root_b);
            rule_swap_b(root_b);
            rule_shift_b(root_b);
            rule_swap_b(root_b);
        }        
    }
}
*/