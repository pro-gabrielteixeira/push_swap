/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:10:42 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 19:26:56 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}

int	ft_iswhitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str, t_stack **root_a)
{
	long int	result;
	int			neg;
	int			c;

	result = 0;
	c = 0;
	neg = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		neg = 44 - *str++;
	while (ft_isdigit(*str))
	{
		result = (*str++ - 48) + (result * 10);
		if (c++ > 11 || result > INT_MAX || result < INT_MIN)
		{
			ft_dealloc(root_a);
			ft_print_error();
		}
	}
	return ((int)result * neg);
}
