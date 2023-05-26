/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:51:53 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/26 16:24:37 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
#define LIBRARY_H

# include <stdio.h>

typedef struct s_args
{
	int	nbr_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	times_to_eat;
}		t_args;

//main.c
int			get_values(char **argv, t_args *args);

//utils.c
int			ft_atoi(const char *str);
int			ft_whitespace(const char *str, int *ptr_i);

#endif
