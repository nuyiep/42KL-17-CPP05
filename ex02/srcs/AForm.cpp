/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:48 by plau              #+#    #+#             */
/*   Updated: 2023/07/10 23:30:48 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :_name("Default AForm"), _signGrade(LOWEST_GRADE), _executeGrade(LOWEST_GRADE)
{
	this->_signed = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &src) :_name("Copy Constructor AForm"), _signGrade(HIGHEST_GRADE), _executeGrade(HIGHEST_GRADE)
{
	this->_signed = false;
	(*this) = src;
}

AForm &AForm::operator=(const AForm &src)
{
	this->_signed = src._signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecuteGrade() const
{
	return (this->_executeGrade);
}

/* Provides the definition of what() */
std::ostream &operator<<(std::ostream &os, AForm const &obj)
{
	os << BOLD_CYAN "Name: \t\t\t\t" << obj.getName() << std::endl
		<< BOLD_GREEN "Has/has not signed: \t\t" << obj.getSigned() << std::endl
		<< "Grade required to sign: \t" << obj.getSignGrade() << std::endl
		<< "Grade required to execute: \t" << obj.getExecuteGrade() << RESET << std::endl
		<< std::endl;
	return (os);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (BOLD_MAGENTA "[AForm] Grade too high." RESET);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "[AForm] Grade too low." RESET);
}

AForm::AForm(std::string name, int signGrade, int executeGrade) :_name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	this->_signed = false;
	try
	{
		if (this->_signGrade > LOWEST_GRADE || this->_executeGrade > LOWEST_GRADE)
			throw AForm::GradeTooLowException();
		else if (this->_signGrade < HIGHEST_GRADE || this->_executeGrade < HIGHEST_GRADE)
			throw AForm::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
}

void	AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_executeGrade)
		throw AForm::GradeTooLowException();
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	performAction();
}
