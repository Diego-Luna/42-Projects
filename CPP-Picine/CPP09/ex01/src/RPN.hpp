/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:11:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/05/23 18:27:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <array>
#include <string>
#include <fstream>
#include <iostream>

// container map. en el constructor chechar datos
// save info y correr.
class RPN
{
  public:
		RPN(void);
		RPN(const std::string& databaseFile);
    ~RPN(void);

    void saveInfo(std::string& data);
    void getResult(void);


    // Error -> try cath
		class Error : public std::exception {
    public:
        virtual const char* what() const throw();
    };

  private:
    int long long result;
    bool error;
    int numberNumbers;

    std::array<std::string, 20> arr;
    std::array<std::string, 20>::iterator it;

    std::array<int, 10> tem_arr;
    std::array<int, 10>::iterator tem_it;

    // check
    bool checkData(std::string& data);
    void positionFind(std::string& data, size_t *cut_start, size_t *cut_end);
    bool isStringNumber(std::string& str);
};

#endif