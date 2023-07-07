/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:48 by plau              #+#    #+#             */
/*   Updated: 2023/07/07 15:07:18 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :_name("Stationery Purchase Order"), _signGrade(LOWEST_GRADE), _executeGrade(LOWEST_GRADE)
{
	this->_signed = false;
}

Form::~Form()
{
}

Form::Form(const Form &src) :_name("Car Purchase Order"), _signGrade(HIGHEST_GRADE), _executeGrade(HIGHEST_GRADE)
{
	this->_signed = false;
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

Form::Form(std::string name, int signGrade, int executeGrade) :_name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->_signed = false;
	try
	{
		if (this->_signGrade > LOWEST_GRADE || this->_executeGrade > LOWEST_GRADE)
			throw Form::GradeTooLowException();
		else if (this->_signGrade < HIGHEST_GRADE || this->_executeGrade < HIGHEST_GRADE)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
}
