/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:57:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 14:57:59 by dluna-lo         ###   ########.fr       */
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
	  Fixed(const Fixed &src);
	  ~Fixed(void);

		Fixed &operator=(const Fixed &nbr);

		int getRawBits(void) const;
		void setRawBits(int const raw);

  private:
		int _number;
		static const int _numberBits = 8;
};

#endif
