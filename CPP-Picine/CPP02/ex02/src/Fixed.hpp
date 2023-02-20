/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:57:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 13:47:16 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
  public:
	  // Constructors and destructors
	  Fixed(void);
	  Fixed(const int value);
	  Fixed(const float value);
	  Fixed(const Fixed &src);
	  ~Fixed(void);

		Fixed &operator=(const Fixed &nbr);

		Fixed operator+(const Fixed &nbr);
		Fixed operator-(const Fixed &nbr);
		Fixed operator/(const Fixed &nbr);
		Fixed operator*(const Fixed &nbr);

		Fixed &operator++();
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed &operator--();

		bool operator<(const Fixed &nbr) const;
		bool operator<=(const Fixed &nbr) const;
		bool operator>(const Fixed &nbr) const;
		bool operator>=(const Fixed &nbr) const;
		bool operator==(const Fixed &nbr) const;
		bool operator!=(const Fixed &nbr) const;

		int getRawBits(void) const;
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed&	min(Fixed&a, Fixed&b);
		static Fixed&	max(Fixed&a, Fixed&b);
		const static Fixed&	min(const Fixed&a, const Fixed&b);
		const static Fixed&	max(const Fixed&a, const Fixed&b);

  private:
		int _number;
		static const int _numberBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const instance);

#endif
