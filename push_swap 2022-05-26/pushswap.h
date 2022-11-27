/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:35:26 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/22 15:09:34 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_putnbr_base(ssize_t num, char *bas, char c, int *count);
void	ft_putchar(char c, int *count);
int		ft_printf(const char *s, ...);
void	ft_putstr(char	*s, int *count);
typedef struct a_list
{
	ssize_t			data;
	int				index;
	struct a_list	*prev;
	struct a_list	*next;
}	t_list;
void	ft_swap(t_list **a, char check);
void	ft_shift(t_list **a, char check);
void	ft_revshift(t_list **a, char check);
void	ft_push(t_list **a, t_list **b, char check);
void	checkdigit(char **argv);
void	checkrange(t_list **a, ssize_t num);
char	**ft_split(char const *s, char c);
ssize_t	ft_atoi(const char *str);
t_list	*initlists(char **argv, int *count);
void	indexfunc(t_list **a, int count);
void	threesort(t_list **a);
int		sortcheck(t_list **a, int count);
void	sortfunc(t_list	**a, t_list **b, int count);
void	checkloc(t_list **a, int count, int index, char *c);
void	houndred(t_list	**a, t_list **b);
void	pushback(t_list **a, t_list **b, int count);
void	fivehoundred(t_list **a, t_list **b);
void	printlists(t_list **a, int count);
int		mindata(t_list **b);
void	findindex(t_list	**a, long step_a, long revstep_a, long *index);
void	steps(t_list	**a, t_list	**b, int range);
void	steps_b(long index, t_list **b,
			long *step_b, long *revstep_b);
void	checkloc1(t_list **a, t_list *cmp,
			long *step_b, long *revstep_b);
void	steps_a(t_list **a, int range, long *count, long *revcount);
void	freed(t_list **a);
void	checkdublicate(t_list **a);
void	listmaker(int *b, t_list **first, t_list **head, t_list **a);
void	pusherab(long *step_a, long *step_b, t_list **a, t_list **b);
void	revpusherab(long *revstep_a, long *revstep_b, t_list **a, t_list **b);
void	rotate_a(long *step_a, long *revstep_a, t_list **a);
void	rotate_b(long *step_b, long *revstep_b, t_list **b);
void	splitfree(char **num);
void	twosort(t_list **a);

#endif
