/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:48 by plau              #+#    #+#             */
/*   Updated: 2023/07/06 12:37:51 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :_name("John Doe"), _signGrade(75), _executeGrade(130)
{
	this->_signed = false;
}

Form::~Form()
{
}

Form::Form(const Form &src)
{
	(*this) = src;
}

Form &Form::operator=(const Form &src)
{
	(void)src;
	return (*this);
}

std::ostream &operator<<(std::ostream *os, Form const &obj)
{
	
}
