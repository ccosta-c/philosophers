/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:47:29 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/14 20:15:55 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_sleep(t_philos *philo)
{
	usleep(philo->data->time_sleep * 1000);
	ft_print(philo, "is sleeping.");
}

int	simulation(t_data *data)
{
	eat(data);
}

int	eat(t_data *data);
{
	pthread_mutex_t 
}
