/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:47:43 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/29 13:28:38 by gateixei         ###   ########.fr       */
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
