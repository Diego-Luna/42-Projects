/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:26:38 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>
# include <exception>

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

		// operator
		Bureaucrat		&operator=(Bureaucrat const & src);


		void        	incrementGrade(int increment);
    void        	decrementGrade(int decrement);

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
