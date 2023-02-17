/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:09:17 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/17 15:09:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0 || name.empty())
	{
		return NULL;
	}

	Zombie *array = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		array[i].set_name(name);
	}
	return (array);
}
