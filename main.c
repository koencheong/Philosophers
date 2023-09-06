/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:38:31 by kcheong           #+#    #+#             */
/*   Updated: 2023/08/19 18:38:31 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// argv[1] number_of_philosophers 
// argv[2] time_to_die 
// argv[3] time_to_eat
// argv[4] time_to_sleep
// argv[5] (optional) number_of_meals

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));	
}

void	*philofunc(void* arg)
{
	t_philo	*philo;
	time_t	time;

	philo = (t_philo *)arg;
	time = get_time();
	printf("%ld %d is thinking\n", time, philo->idnum);
	
	if (pthread_mutex_lock(&philo->right_fork) == 0)
	{
		if (pthread_mutex_lock(&philo->left_fork) == 0)
			printf("%d is eating\n", philo->idnum);
	}
	else
		printf("%d is sleeping\n", philo->idnum);
	
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_info		*info;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		info = (t_info *)malloc(sizeof(t_info));
		info->n_philo = atoi(argv[1]);
		// info->idnum = 0;
		info->t2think = atoi(argv[2]);
		info->t2eat = atoi(argv[3]);
		info->t2zzz = atoi(argv[4]);

		while (i < info->n_philo)
		{
			// printf("debug\n");
			info->philo_tid = (pthread_t *)malloc(info->n_philo * sizeof(pthread_t));
			info->philo = (t_philo *)malloc(info->n_philo * sizeof(t_philo));
			info->philo[i].info = info;
			info->philo[i].idnum = i + 1;
			pthread_mutex_init(&info->philo[i].mutex, NULL);
			pthread_mutex_init(&info->philo[i].right_fork, NULL);
			pthread_mutex_init(&info->philo[i].left_fork, NULL);
			pthread_create(&info->philo_tid[i], NULL, &philofunc, &info->philo[i]);
			usleep(1);
			i++;
		}

		i = 0;
		while (i < info->n_philo)
    	{
			pthread_join(info->philo_tid[i], NULL);
			i++;
		}
	}
	else
		printf("Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eattime_to_sleep]\n");
	exit(0);
}
