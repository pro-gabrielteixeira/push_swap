/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:49 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/10 04:07:49 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct t_stack {
	int	num;
	struct t_stack *next;
} stack;

//lst_function.c
void ft_dealloc(stack* root);
void ft_lstadd_front(stack** root, int value);
void ft_lstadd_back(stack** root, int value);

//instructions.c
void swap_element(stack** root);
void push_element(stack** root, stack** aux);
void shift_element(stack** root);
void reverse_shift(stack** root);

//rules.c
void rule_swap_a(stack** root);
void rule_swap_b(stack** root);
void rule_swap_ss(stack** root_a, stack** root_b);
void rule_push_a(stack** root_a, stack** root_b);
void rule_push_b(stack** root_a, stack** root_b);

//rules_2.c
void rule_shift_a(stack** root_a);
void rule_shift_b(stack** root_b);
void rule_shift_rr(stack** root_a, stack** root_b);
void rule_reverse_a(stack** root_a);
void rule_reverse_b(stack** root_b);

//rules_3.c
void rule_reverse_rrr(stack** root_a, stack** root_b);

#endif
