/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:47:43 by gateixei          #+#    #+#             */
/*   Updated: 2023/02/11 19:32:27 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack **root)
{
	t_stack	*curr;
	int		i;	

	curr = (*root);
	i = curr->num;
	while (curr)
	{
		if (i > curr->num)
			i = curr->num;
		curr = curr->next;
	}
	return (i);
}

int	get_max(t_stack **root)
{
	t_stack	*curr;
	int		i;	

	curr = *root;
	i = curr->num;
	while (curr)
	{
		if (i < curr->num)
			i = curr->num;
		curr = curr->next;
	}
	return (i);
}

void	ft_print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_pivot(t_stack **root)
{
	long int		result;
	unsigned int	i;
	t_stack			*curr;

	i = 0;
	result = 0;
	curr = (*root);
	while (curr != NULL)
	{
		result += curr->num;
		curr = curr->next;
		i++;
	}
	return ((int)result / i);
}

int	get_size(t_stack **root)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = *root;
	while ((curr) != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
