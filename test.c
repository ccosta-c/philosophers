/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:21:45 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/05/23 14:23:36 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	*exec(void *arg)
{
	static int		counter;

	(pthread_mutex_t)arg;
	pthread_mutex_lock(arg);
	counter++;
	printf("number %i\n", counter);
	pthread_mutex_unlock(arg);
	return (arg);
}

int	main(void)
{
	int				i;
	int				error;
	pthread_t		tid[100];
	pthread_mutex_t	lock;
	int				nbr_threads;

	nbr_threads = 100;
	i = 0;
	if (pthread_mutex_init(&lock, NULL) != 0)
		printf("MUTEX INIT ERROR!\n");
	while (i < nbr_threads)
	{
		error = pthread_create((&tid[i]), NULL, &exec, &lock);
		usleep(1000);
		if (error != 0)
			printf("THREAD ERROR!\n");
		i++;
	}
	i = 0;
	pthread_mutex_destroy(&lock);
	while (i < nbr_threads)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (0);
}
