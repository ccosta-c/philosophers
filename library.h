/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:51:53 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/29 11:44:15 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philos
{
	int	id;
	int	times_eaten;
}		t_philos;

typedef struct s_data
{
	int				nbr_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_to_eat;
	t_philos		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	abeprint;
}					t_data;

//main.c
int			get_values(char **argv, t_data *args);
int			initialize(t_data *data);

//utils.c
int			ft_atoi(const char *str);
int			ft_whitespace(const char *str, int *ptr_i);

#endif
