/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:48 by plau              #+#    #+#             */
/*   Updated: 2023/07/06 14:52:54 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :_name("John Doe"), _signGrade(LOWEST_GRADE), _executeGrade(LOWEST_GRADE)
{
	this->_signed = false;
}

Form::~Form()
{
}

Form::Form(const Form &src) :_name("PY"), _signGrade(70), _executeGrade(130)
{
	(*this) = src;
}

Form &Form::operator=(const Form &src)
{
	this->_signed = src._signed;
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

/* Provides the definition of what() */
std::ostream &operator<<(std::ostream &os, Form const &obj)
{
	os << BOLD_CYAN "Name: \t\t\t\t" << obj.getName() << std::endl
		<< BOLD_GREEN "Has/has not signed: \t\t" << obj.getSigned() << std::endl
		<< "Grade required to sign: \t" << obj.getSignGrade() << std::endl
		<< "Grade required to execute: \t" << obj.getExecuteGrade() << std::endl
		<< std::endl;
		RESET;
	return (os);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return (BOLD_MAGENTA "[Form] Grade too high." RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "[Form] Grade too low." RESET);
}


