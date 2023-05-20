/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/20 19:40:55 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>


// container map.
// check file
// chec info.
// save info.
class BitcoinExchange
{
  public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange(void);

    //set and get
    std::string setData(std::string& data);
    int setIndex(std::map<int, std::string>::iterator &itr);

    int getIndex(void);
    int getMax(void);

    // check
    bool checkMount();

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

    int setMax(int newMax);
};

#endif