/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javierzaragozatejeda <javierzaragozatej    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:36:07 by javierzarag       #+#    #+#             */
/*   Updated: 2025/04/04 22:51:37 by javierzarag      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_cleanup(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->philos)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(philos[i].left_fork);
		pthread_mutex_destroy(philos[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(philos->print);
	free(philos->left_fork);
	free(philos->right_fork);
	free(philos->print);
	free(philos);
}
