/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:52:46 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 15:12:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#	define CONVERSION_H

# include <iostream>
# include <cmath>

class Conversion
{
private:
	private:
		bool				_isValid;
		std::string			_str;
		std::string				_type;

		void				printResult_all();
		void				printResult_in_c(char c);

	public:
		Conversion(std::string str);
		Conversion(const Conversion & src);
		~Conversion();

		Conversion&	operator=(Conversion const&);

		void				detectType();
		void				printResult();
};

#endif