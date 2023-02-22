/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/22 14:16:55 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATCLASS_HPP
# define BUREAUCRATCLASS_HPP

# include <iostream>
# include <exception>
#	include "Form.hpp"

class Form;

class Bureaucrat
{
  public:
	  // Constructors and destructors
	  Bureaucrat(void);
		Bureaucrat(std::string const & _name, int _grade);
	  Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);

		// basic
    std::string 	getName(void) const;
		int         	getGrade(void) const;
		void        	incrementGrade(int increment);
    void        	decrementGrade(int decrement);
		void					signForm(Form &src) const;


		// operator
		Bureaucrat		&operator=(Bureaucrat const & src);

		// try cath
		class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

  protected:
		std::string const	_name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif
