/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:04:49 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 19:26:24 by gateixei         ###   ########.fr       */
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
	int				num;
	struct t_stack	*next;
}		t_stack;

//push_swap.c
void	init_sort(t_stack **root_a, t_stack **root_b);
void	sort_small(t_stack **root_a, t_stack **root_b, int size);
void	sort_medium(t_stack **root_a, t_stack **root_b, int size);
void	sort_large(t_stack **root_a, t_stack **root_b, int size);

//lst_function.c
void	ft_dealloc(t_stack **root);
void	ft_lstadd_front(t_stack **root, int value);
void	ft_lstadd_back(t_stack **root, int value);
int		lstlast(t_stack **root);

//instructions.c
void	swap_element(t_stack **root);
void	push_element(t_stack **root, t_stack **aux);
void	shift_element(t_stack **root);
void	reverse_shift(t_stack **root);

//rules.c
void	rule_swap_a(t_stack **root);
void	rule_swap_b(t_stack **root);
void	rule_swap_ss(t_stack **root_a, t_stack **root_b);
void	rule_push_a(t_stack **root_a, t_stack **root_b);
void	rule_push_b(t_stack **root_a, t_stack **root_b);

//rules_2.c
void	rule_shift_a(t_stack **root_a);
void	rule_shift_b(t_stack **root_b);
void	rule_shift_rr(t_stack **root_a, t_stack **root_b);
void	rule_reverse_a(t_stack **root_a);
void	rule_reverse_b(t_stack **root_b);

//rules_3.c
void	rule_reverse_rrr(t_stack **root_a, t_stack **root_b);

//utils.c
int		get_min(t_stack **root);
int		get_max(t_stack **root);
void	ft_print_error(void);
int		ft_pivot(t_stack **root);
int		get_size(t_stack **root);

//ft_atoi.c
int		ft_isdigit(int c);
int		ft_iswhitespace(char c);
int		ft_atoi(const char *str, t_stack **root_a);

//sorting_small.c
void	sort_t_stack_small_b(t_stack **root_a, t_stack **root_b);
void	sort_t_stack_small_a(t_stack **root_a);

//sorting_medium.c
int		ft_check_small(t_stack **small, int i);
void	ft_get_small(t_stack **small, t_stack **root, int size);
int		sorting_medium_b(t_stack **root_a, t_stack **root_b,
			t_stack **small_sort, int count);
int		swap_sorting(t_stack **root);
void	sorting_medium_a(t_stack **root_a, t_stack **root_b);

#endif
