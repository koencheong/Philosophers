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

void	*philofunc(void* arg)
{
	(void)arg;
	printf("Hi from thread!\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int		n_philo;
	t_philo	*philo_vars;

	philo_vars = NULL;
	if (argc == 5)
	{
		n_philo = atoi(argv[1]);
		// philo_vars = (t_philo *)malloc(n_philo * sizeof(t_philo));
		philo_vars->t2think = strdup(atoi(argv[2]));
		philo_vars->t2eat = atoi(argv[3]);
		philo_vars->t2zzz = atoi(argv[4]);
		
		int			i;

		i = 0;
		while (i < n_philo)
		{
			pthread_create(&philo_vars->philo_ids[i], NULL, &philofunc, NULL);
			i++;
		}
		pthread_join(philo_vars->philo_ids[i], NULL);
	}
	else
		printf("Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eattime_to_sleep]\n");
	exit(0);
}