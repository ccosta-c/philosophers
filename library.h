/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:51:53 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/14 20:17:38 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philos
{
	pthread_t		philo;
	int				id;
	int				times_eaten;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	t_data			*data;
}				t_philos;

typedef struct s_overseer
{
}			t_overseer;

typedef struct s_data
{
	int				nbr_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_to_eat;
	t_philos		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_overseer		overseer;
	long long		start_time;
}					t_data;




//main.c
int			get_values(char **argv, t_data *args);

//initialize.c
int			initialize_forks(t_data *data);
int			initialize_philos(t_data *data);
int			simulation_prep(t_data *data);
int			initialize(t_data *data);

//utils.c
int			ft_atoi(const char *str);
int			ft_whitespace(const char *str, int *ptr_i);
long long	time_ms(long long start_time);
long long	get_time(void);
void		ft_print(t_philos *philo, char *str);

//actions.c

void		ft_sleep(t_philos *philo);
int			simulation(t_data *data);

#endif
