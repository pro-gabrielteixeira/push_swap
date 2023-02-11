/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:39 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 19:28:12 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_t_stack_a(t_stack **root_a, t_stack **root_b,
	t_stack **small_num, t_stack **small_sort)
{
	int	count;
	int	i;

	count = 0;
	i = get_size(small_num);
	while ((*root_a) && i)
	{
		if (!(ft_check_small(small_num, (*root_a)->num)))
		{
			count = sorting_medium_b(root_a, root_b, small_sort, count);
			i--;
		}
		else
			rule_shift_a(root_a);
	}
	return (count);
}

void	sort_medium(t_stack **root_a, t_stack **root_b, int size)
{
	t_stack	*small_num;
	t_stack	*small_sort;
	int		count;

	small_num = NULL;
	small_sort = NULL;
	ft_get_small(&small_num, root_a, size);
	ft_get_small(&small_sort, &small_num, size / 2);
	count = sorting_t_stack_a(root_a, root_b, &small_num, &small_sort);
	while (count--)
		rule_reverse_b(root_b);
	ft_dealloc(&small_num);
	ft_dealloc(&small_sort);
	if (get_size(root_a) >= 1)
		sort_medium(root_a, root_b, size);
	else
		sorting_medium_a(root_a, root_b);
}

void	sort_small(t_stack **root_a, t_stack **root_b, int size)
{
	int	count;

	count = 0;
	while (count < (size / 2))
	{
		if ((*root_a)->num == get_max(root_a)
			|| (*root_a)->num == get_min(root_a))
		{
			sort_t_stack_small_b(root_a, root_b);
			count++;
		}
		else
			rule_shift_a(root_a);
	}
	while ((*root_b) != NULL)
	{
		rule_push_a(root_a, root_b);
		sort_t_stack_small_a(root_a);
	}
}

void	init_sort(t_stack **root_a, t_stack **root_b)
{
	int	i;

	i = get_size(root_a);
	if (i <= 3)
		sort_t_stack_small_a(root_a);
	else if (i <= 5)
		sort_small(root_a, root_b, i);
	else if (i <= 50)
		sort_medium(root_a, root_b, i / 3);
	else if (i <= 100)
		sort_medium(root_a, root_b, i / 6);
	else if (i <= 250)
		sort_medium(root_a, root_b, i / 8);
	else
		sort_medium(root_a, root_b, i / 10);
}
