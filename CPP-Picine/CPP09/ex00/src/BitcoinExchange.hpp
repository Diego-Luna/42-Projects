/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/21 18:20:11 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>



// container map. en el constructor chechar datos
// save info y correr.

class BitcoinExchange
{
  public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange(void);

    std::string runData(std::string& data);

    // check
    bool checkMount(std::string& data);

    // Error -> try cath
		class formatWrong : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class dateError : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class valueError : public std::exception {
    public:
        virtual const char* what() const throw();
    };

  private:
    int max;
    std::map<int, std::string> m1;
    std::map<int, std::string>::iterator itr;


};

#endif