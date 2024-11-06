/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:15:15 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/30 09:28:59 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				n;
	int				index;
	int				chepeast;
	int				cost;
	int				above_medium;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

int			ft_only_num(char *str);
int			ft_stack_size(t_stack *stack_b);
int			ft_bit_size(int size);
void		ft_the_action(t_stack *stack_a, int limit);
void		ft_take_index_number(t_stack *stack);
int			ft_check_if_is_sorted(t_stack *stack);
void		print(t_stack *stack);
void		ft_sort_two(t_stack **stack);
void		ft_sort_three(t_stack **stack);
void		ft_sort_four(t_stack **stack_a, t_stack	**stack_b);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_large(t_stack **stack_a, t_stack **stack_b);
void		ft_rrb(t_stack **stack_b, int stop);
void		ft_rra(t_stack **stack, int stop);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rb(t_stack **stack_b, int stop);
void		ft_ra(t_stack **stack_a, int stop);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_sa(t_stack **stack_a, int stop);
void		ft_sb(t_stack **stack_b, int stop);

/*File name: push_utils.c*/
int			ft_isalnum_update(char *str);
void		ft_print_stack(t_stack *stack);

/*File name: push_error_message.c*/
void		ft_free_nodes(t_stack *stack);
void		ft_error_message(int n, char **matrix, t_stack *stack);

/*File name: push_stack_operations.c*/
int			stack_is_full(t_stack *stack);
int			stack_is_empty(t_stack *stack);
void		ft_add_to_stack(t_stack **head, int n);

/*File name: push_verifications.c */
void		ft_see_duplicates(t_stack *stack);
void		ft_get_number_from_matrix(char **matrix, t_stack *stack);
void		ft_arg_is_str(char **av, t_stack *stack);
void		ft_arg_is_arg(int ac, char **av, t_stack *stack);

#endif
