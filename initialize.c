/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:20:32 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/14 20:09:13 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	initialize_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
	if (!data->forks)
		return (-1);
	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			printf("Error in the creation of the forks.");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	initialize_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof (t_philos) * data->nbr_philos);
	if (!data->philos)
		return (-1);
	while (i < data->nbr_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].times_eaten = 0;
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

int	simulation_prep(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_create(&data->philos[i]->philo, NULL, &simulation, &data->philos[i]);
	}
}

int	initialize(t_data *data)
{
	data->start_time = get_time();
	if (pthread_mutex_init(&data->print, NULL))
	{
		printf("Error in the print lock");
		return (-1);
	}
	if (initialize_forks(data) == -1)
		return (-1);
	if (initialize_philos(data) == -1)
	{
		printf("Error in the philosophers init.");
		return (-1);
	}
}
