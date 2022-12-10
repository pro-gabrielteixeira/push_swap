/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:05:41 by gateixei          #+#    #+#             */
/*   Updated: 2022/12/10 04:06:37 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rule_reverse_rrr(stack** root_a, stack** root_b)
{
    reverse_shift(root_a);
    reverse_shift(root_b);
    write(1, "rrr\n", 4);
}