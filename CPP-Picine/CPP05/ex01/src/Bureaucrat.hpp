/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 21:27:08 by diegofranci      ###   ########.fr       */
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
	  Bureaucrat(std::string _name, int	_grade);
	  Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();

		// basic
		void        	setName(const std::string &name);
    std::string 	getName() const;
		int getGrade(void);
		int         	getGrade() const;

		// operator
		Bureaucrat		&operator=(Bureaucrat const & src);


		void        	minusGrade(int increment);
    void        	addGrade(int decrement);

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
		std::string	_name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif
