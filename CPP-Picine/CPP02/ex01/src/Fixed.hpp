/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:57:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 15:11:03 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:

	int _value;
	const static int _bits = 8;

public:

	Fixed(void);
	Fixed(const Fixed &newValue);
	Fixed(const int nbr);
	Fixed(const float nbr);
	~Fixed(void);
	Fixed &operator=(const Fixed &nbr);

	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, Fixed const &nbr);

#endif
