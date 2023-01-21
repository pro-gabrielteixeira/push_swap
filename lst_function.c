/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:02:38 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/29 13:24:45 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_dealloc(stack* root)
{
	if (root != NULL)
	{
		ft_dealloc(root->next);
		free(root);
	}
}

void ft_lstadd_front(stack** root, int value)
{
	stack*	new_lst;
	
	new_lst = malloc(sizeof(stack));
	new_lst->num = value;
	new_lst->next = *root;
	(*root) = new_lst;
}

void ft_lstadd_back(stack** root, int value)
{
	stack* curr;
	stack*	new_lst;
	
	new_lst = malloc(sizeof(stack));
	new_lst->num = value;
	new_lst->next = NULL;
	curr = *root;
	if (curr == NULL)
	{
		(*root) = new_lst;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_lst;
}

int lstlast(stack** root)
{
	stack* curr;

	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr->num);
}