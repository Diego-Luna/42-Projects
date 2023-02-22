/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:47:33 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/22 14:16:39 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMCLASS_HPP
# define FORMCLASS_HPP

#	include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  public:
	  // Constructors and destructors
	  Form(void);
		Form(std::string const & _name, int _gradeSingIn, int _gradeExecute);
	  Form(const Form &src);
		~Form(void);

		// basic
		std::string 	getName(void) const;
		bool 					getSigned(void) const;
		int         	getGradeSingIn(void) const;
		int         	getGradeExecute(void) const;
		void beSigned(const Bureaucrat &src);

		// operator
		Form		&operator=(Form const & src);

		// try cath
		class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

  private:
		std::string const	_name;
		bool	_signed;
		const int _gradeSingIn;
		const int _gradeExecute;

};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif
