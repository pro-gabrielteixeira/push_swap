/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:36:25 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 19:29:50 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_small(t_stack **small, int i)
{
	t_stack	*curr;

	curr = (*small);
	while (curr)
	{
		if (curr->num == i)
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}

void	ft_get_small(t_stack **small, t_stack **root, int size)
{
	t_stack	*curr;
	int		i;

	while (size--)
	{
		curr = (*root);
		i = get_max(root);
		while (curr)
		{
			if (i > curr->num && ft_check_small(small, curr->num))
				i = curr->num;
			curr = curr->next;
		}
		ft_lstadd_back(small, i);
	}
}

int	sorting_medium_b(t_stack **root_a, t_stack **root_b,
	t_stack **small_sort, int count)
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

int	swap_sorting(t_stack **root)
{
	t_stack	*curr;
	int		i;
	int		j;

	i = get_max(root);
	j = 0;
	curr = (*root);
	while (curr->num != i)
	{
		j++;
		curr = curr->next;
	}
	if (j > (get_size(root) / 2))
		return (FALSE);
	else
		return (TRUE);
}

void	sorting_medium_a(t_stack **root_a, t_stack **root_b)
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
