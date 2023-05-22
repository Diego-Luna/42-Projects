/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/22 17:47:54 by dluna-lo         ###   ########.fr       */
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

    void runData(void);

    // check
    bool checkMount(std::string& data);

    // Error -> try cath
		class formatWrong : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class dataError : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class valueError : public std::exception {
    public:
        virtual const char* what() const throw();
    };

  private:
    size_t max;
    std::string name;
    std::map<int, std::string> m1;
    std::map<int, std::string>::iterator itr;

    int numberCaracterRepeat(std::string& data, char c);
    bool _checkdata(std::string& data);
    bool _checkvalue(std::string& data);

};

#endif