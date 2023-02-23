/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:47:33 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:20:55 by dluna-lo         ###   ########.fr       */
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
		Form(std::string const & _name, std::string const & _target, bool	_signed, int _gradeSingIn, int _gradeExecute);
	  Form(const Form &src);
		virtual ~Form(void);
		virtual void execute(Bureaucrat const & user) const = 0;

		// basic
		std::string 	getName(void) const;
		std::string 	getTarget(void) const;
		bool 					getSigned(void) const;
		int         	getGradeSingIn(void) const;
		int         	getGradeExecute(void) const;
		void beSigned(const Bureaucrat &src);

		void validateExecute(Bureaucrat const & user) const;

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

		class FormIsNotSignException: public std::exception{
			public:
					virtual const char* what() const throw();
		};

  private:
		std::string const	_name;
		std::string const	_target;
		bool	_signed;
		const int _gradeSingIn;
		const int _gradeExecute;

};

// std::ostream& operator<<(std::ostream& out, const Form& src);
std::ostream& operator<<(std::ostream&, const Form&);

#endif
