/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:49 by gateixei          #+#    #+#             */
/*   Updated: 2023/01/06 14:42:13 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct t_stack {
	int	num;
	struct t_stack *next;
} stack;

//push_swap.c
void init_sort(stack** root_a, stack** root_b);
void sort_small(stack** root_a, stack** root_b, int size);
void sort_medium(stack** root_a, stack** root_b);
void sort_large(stack** root_a, stack** root_b, int size);

//lst_function.c
void ft_dealloc(stack** root);
void ft_lstadd_front(stack** root, int value);
void ft_lstadd_back(stack** root, int value);
int lstlast(stack** root);

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

//utils.c
int get_min(stack** root);
int get_max(stack** root);
int ft_strlen(char* str);
void ft_print_error(void);
int ft_pivot(stack** root);

//ft_atoi.c
int	ft_isdigit(int c);
int	ft_iswhitespace(char c);
int	ft_atoi(const char *str, stack** root_a);

//sorting_small.c
void sort_stack_small_b(stack** root_a, stack** root_b);
void sort_stack_small_a(stack** root_a);

#endif
