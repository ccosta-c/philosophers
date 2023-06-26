/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:47:29 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/21 12:09:43 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	*simulation(void *philo)
{
	t_philos	*copy;

	copy = (t_philos *)philo;
	while (1)
	{
		if (grab_forks(copy) == -1)
			break ;
		ft_eat(copy);
		ft_sleep(copy);
		ft_print(copy, "is thinking.");
	}
	return (copy);
}

void	ft_eat(t_philos *philo)
{
	philo->last_meal = time_ms(philo->data->start_time);
	ft_print(philo, "is eating.");
	philo->data->last_meal = time_ms(philo->data->start_time);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	philo->times_eaten++;
}

void	ft_sleep(t_philos *philo)
{
	usleep(philo->data->time_sleep * 1000);
	ft_print(philo, "is sleeping.");
}

int	grab_forks(t_philos *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_print(philo, "has taken a fork.");
	if (philo->data->nbr_philos == 1)
		return (-1);
	pthread_mutex_lock(philo->r_fork);
	ft_print(philo, "has taken a fork.");
	return (0);
}
