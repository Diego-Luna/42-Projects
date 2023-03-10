/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:52:46 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 08:45:56 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#	define CONVERSION_H

# include <iostream>

class Conversion
{
private:
	private:
		std::string			_str;
		long double			_nbr;
		bool				_isNumber;

public:
	Conversion(std::string str);
	Conversion(const Conversion & src);
	~Conversion();

	Conversion&	operator=(Conversion const&);

	void				detectType() const;
	void				printResult() const;
};

#endif