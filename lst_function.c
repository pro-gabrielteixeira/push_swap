/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:02:38 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 19:27:44 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dealloc(t_stack **root)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = (*root);
	while (curr != NULL)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}

void	ft_lstadd_front(t_stack **root, int value)
{
	t_stack	*new_lst;

	new_lst = malloc(sizeof(t_stack));
	new_lst->num = value;
	new_lst->next = *root;
	(*root) = new_lst;
}

void	ft_lstadd_back(t_stack **root, int value)
{
	t_stack	*curr;
	t_stack	*new_lst;

	new_lst = malloc(sizeof(t_stack));
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

int	lstlast(t_stack **root)
{
	t_stack	*curr;

	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr->num);
}
