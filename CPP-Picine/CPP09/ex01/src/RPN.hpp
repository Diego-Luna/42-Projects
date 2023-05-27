/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/27 19:49:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <array>
#include <string>
#include <fstream>
#include <iostream>

class RPN
{
  public:
		RPN(void);
		RPN(const RPN& copy);
    ~RPN(void);

    void saveInfo(std::string& data);
    void getResult(void);

    RPN &operator=(const RPN &copy);

    // Error -> try cath
		class Error : public std::exception {
    public:
        virtual const char* what() const throw();
    };

  private:
    long long result;
    bool error;
    int numberNumbers;

    std::array<std::string, 30> arr;
    std::array<std::string, 30>::iterator it;

    std::array<std::string, 30> tem_arr;
    std::array<std::string, 30>::iterator tem_it;

    // check
    bool checkData(std::string& data);
    void positionFind(std::string& data, size_t *cut_start, size_t *cut_end);
    bool isStringNumber(std::string& str);
};

#endif