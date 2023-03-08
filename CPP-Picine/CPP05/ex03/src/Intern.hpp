/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:33:05 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/08 13:51:16 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		// ~Intern();
		virtual ~Intern();
		Intern &operator=(const Intern& src);

		Form *makeForm(std::string name, std::string target);

		// try cath
		class NotValid : public std::exception {
    public:
        virtual const char* what() const throw();
    };

	private:
		std::string _form[3];
};

#endif
