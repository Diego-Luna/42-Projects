/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:55:27 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/12 16:57:58 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &src1, T &src2){
	T temp = src1;
	src1 = src2;
	src2 = temp;
}

template <typename T>
T min(T const& first, T const& second){
	// return (first < second ? first : second);
	if (first < second)
	{
		return first;
	}
	return second;
}

template <typename T>
T max(T const& first, T const& second) {
	// return (first > second ? first : second);
	if (first > second)
	{
		return first;
	}
	return second;
}

#endif