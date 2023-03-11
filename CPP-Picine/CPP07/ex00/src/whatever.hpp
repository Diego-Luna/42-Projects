/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:12:04 by diegofranci       #+#    #+#             */
/*   Updated: 2023/03/11 09:12:45 by diegofranci      ###   ########.fr       */
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
	return (first < second ? first : second);
}

template <typename T>
T max(T const& first, T const& second) {
	return (first > second ? first : second);
}

#endif