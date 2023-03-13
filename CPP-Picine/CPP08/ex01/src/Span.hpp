/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:30:21 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/13 17:57:06 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
#	include <vector>

class Span
{
  public:
	  // Constructors and destructors
	  Span(void);
	  Span(unsigned int num);
	  Span(const Span &src);
		~Span(void);

    Span &operator=(const Span &src);

		// basic
		void addNumber(int add);
		int shortestSpan(void);
		int longestSpan(void);

  private:
		// int *_array;
		void check_size(std::string	msg, bool add);
		std::vector<int> _array;
		unsigned int _size;
		unsigned int _realy;
		bool _is;
};


#endif