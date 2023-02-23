/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:26:06 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:26:09 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--------Creating and presenting everyone--------" << std::endl;
    Form form;
    Form sauce("super sauce", 100, 100);
    Bureaucrat taco("taco", 10);
    Bureaucrat zombie("zombie", 110);
    std::cout << form << std::endl;
    std::cout << taco << std::endl;

    std::cout << "\n----teste------" << std::endl;
    try {
      form.beSigned(zombie);
      zombie.signForm(form);
    }
    catch (std::exception& ex){
      std::cout << ex.what() << std::endl;
    }

    std::cout << "\n----teste------" << std::endl;
    try {
      sauce.beSigned(taco);
      std::cout << "-sauce.beSigned(taco)" << std::endl;
      taco.signForm(sauce);
    }
     catch (std::exception& ex){
      std::cout << ex.what() << std::endl;
    }

    return 0;
}