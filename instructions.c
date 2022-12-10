/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:13:00 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/10 03:22:22 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_element(stack** root)
{
    stack* aux;
    stack* curr;

    curr = *root;
    aux = curr->next;
    if (aux)
    {
        curr->next = aux->next;
        aux->next = *root;
        *root = aux;   
    }
}

void push_element(stack** root, stack** aux)
{
    stack* curr;

    curr = *aux;
    if(curr)
    {
        ft_lstadd_front(root, curr->num);
        *aux = curr->next;
        free(curr);
    } 
}

void shift_element(stack** root)
{
    stack* curr;

    curr = *root;
    ft_lstadd_back(root, curr->num);
    *root = curr->next;
    free(curr);
}

void reverse_shift(stack** root)
{
    stack*  curr;
    stack*  aux;

    curr = *root;
    while (curr->next != NULL)
        curr = curr->next;
    ft_lstadd_front(root, curr->num);
    curr = *root;
    while (curr->next->next != NULL)
        curr = curr->next;
    aux = curr;
    curr = curr->next;
    aux->next = NULL;
    free(curr);
}