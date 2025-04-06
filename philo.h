/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:20:19 by javierzarag       #+#    #+#             */
/*   Updated: 2025/04/06 17:13:35 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct t_data
{
	int 		philos;
	int 		time_to_eat;
	int 		time_to_die;
	int 		time_to_sleep;
	int 		time_to_think;
	int 		number_of_times_eaten;
	int 		run;
	int 		value;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	long long   start_time;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				philos;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*print;
	int				times_eaten;
	int				start_time;
	long long		last_meal_time;
	int				*stop;
	pthread_t		thread;
	t_data	*data;
}				t_philo;

void    ft_start_program(t_data *data);
void    ft_start_philosophers(t_data *data, char **argv);
void    ft_create_table(t_data *data);
void    ft_death(t_philo *philos, t_data *data);
void    ft_cleanup(t_philo *philos);
void    ft_died(t_philo *philo);
void    ft_print(t_philo *philo, char *print);
void    ft_order(t_philo *philo);
void    ft_unlock(t_philo *philo);
void    ft_step(t_philo *philo);
void    ft_wait(int time);
long long    ft_time(void);
void    ft_wait(int time);
int    ft_check_all_args(char **argv);
int     ft_check_if_num(char *str);
int     ft_mini_atoi(char *str);
void    *ft_table(void   *arg);
t_philo    ft_struct_philo(t_data *data, int who);

#endif