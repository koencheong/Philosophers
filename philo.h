/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheong <kcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:29:48 by kcheong           #+#    #+#             */
/*   Updated: 2023/08/19 19:29:48 by kcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// stdlib.h:   malloc, free
// string.h:   memset
// unistd.h:   write, usleep
// sys/time.h: gettimeofday
// pthread.h:  pthread_create, pthread_detach, phthread_join, pthread_mutex_init,
// 			   pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

# include <stdio.h> 

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_info;

typedef struct	s_philo
{
	s_info			*info;
	pthread_t		*philo_tid;
	int				idnum;
	pthread_mutex_t	mutex;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;

}	t_philo;

typedef struct	s_info
{
	int			n_philo;
	int			t2eat;
	int			t2zzz;
	int			t2think;
	t_philo		*philo;
	pthread_t	*philo_tid;
}	t_info;


#endif