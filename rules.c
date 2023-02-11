/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:36:07 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 18:50:31 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_swap_a(stack **root)
{
	swap_element(root);
	write(1, "sa\n", 3);
}

void	rule_swap_b(stack **root)
{
	swap_element(root);
	write(1, "sb\n", 3);
}

void	rule_swap_ss(stack **root_a, stack **root_b)
{
	swap_element(root_a);
	swap_element(root_b);
	write(1, "ss\n", 3);
}

void	rule_push_a(stack **root_a, stack **root_b)
{
	push_element(root_a, root_b);
	write(1, "pa\n", 3);
}

void	rule_push_b(stack **root_a, stack **root_b)
{
	push_element(root_b, root_a);
	write(1, "pb\n", 3);
}
