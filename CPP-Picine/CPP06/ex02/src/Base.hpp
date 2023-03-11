/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:44:23 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 17:50:21 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#include <iostream>

// Class declaration
class Base {
 public:
  virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
