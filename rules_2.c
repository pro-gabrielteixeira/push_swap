/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:57:52 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 19:28:33 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_shift_a(t_stack **root_a)
{
	shift_element(root_a);
	write(1, "ra\n", 3);
}

void	rule_shift_b(t_stack **root_b)
{
	shift_element(root_b);
	write(1, "rb\n", 3);
}

void	rule_shift_rr(t_stack **root_a, t_stack **root_b)
{
	shift_element(root_a);
	shift_element(root_b);
	write(1, "rr\n", 3);
}

void	rule_reverse_a(t_stack **root_a)
{
	reverse_shift(root_a);
	write(1, "rra\n", 4);
}

void	rule_reverse_b(t_stack **root_b)
{
	reverse_shift(root_b);
	write(1, "rrb\n", 4);
}
