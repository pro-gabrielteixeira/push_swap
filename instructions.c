/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:13:00 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/13 20:54:20 by gateixei         ###   ########.fr       */
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

void push_element(stack** root_add, stack** root_rm)
{
    stack* curr;
    stack* aux;

    curr = *root_rm;
    if(curr->next != NULL)
    {
        aux = curr->next;
        curr->next = (*root_add);
        (*root_rm) = aux;
        (*root_add) = curr;
    } 
    else
    {
        ft_lstadd_front(root_rm, curr->num);
        free(curr);
    }
}

void shift_element(stack** root)
{
    stack* curr;

    curr = *root;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = (*root);
    curr->next->next = NULL;
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