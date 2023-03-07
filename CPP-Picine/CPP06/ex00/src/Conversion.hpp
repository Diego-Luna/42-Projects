/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:52:46 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/07 18:23:55 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef CONVERSION_H
#define CONVERSION_H

# include <iostream>

class Conversion
{
private:
	/* data */
public:
	Conversion(void);
	Conversion(char *str);
	Conversion(const Conversion & src);
	~Conversion();
};


#ifdef