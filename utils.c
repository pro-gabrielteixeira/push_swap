/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:47:43 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/14 00:58:13 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min(stack** root)
{
    stack* curr;
    int i;

    curr = *root;
    i = curr->num;
    while (curr->next != NULL)
    {
        if(i > curr->num)
            i = curr->num;
        curr = curr->next;
    }
    return (i);
}