/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:03:17 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/06/20 15:56:04 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_whitespace(const char *str, int *ptr_i)
{
	int	i;
	int	minus;

	i = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	*ptr_i = i;
	return (minus);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = ft_whitespace(nptr, &i);
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

long long	time_ms(long long start_time)
{
	struct timeval	time;
	long long		time_total;
	long long		tmp;

	gettimeofday(&time, NULL);
	tmp = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	time_total = tmp - start_time;
	return (time_total);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		time_total;

	gettimeofday(&time, NULL);
	time_total = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_total);
}

void	ft_print(t_philos *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n", time_ms(philo->data->start_time), philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}
