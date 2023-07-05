/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:10:01 by plau              #+#    #+#             */
/*   Updated: 2023/07/05 15:44:24 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :_name("John Doe")
{
	this->_grade = LOWEST_GRADE;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
	(*this) = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	return (*this);
}

const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/* Since grade 1 is the highest and 150 is the lowest */
/* incrementing a grade 3 will give a grade 2 */
/* If the condition is true and an exception is thrown, */
/* the execution will be transferred to the 'catch' block */
/* and the statement following the 'catch' block */
/* will not be executed */
void Bureaucrat::incrementGrade(int num)
{
	int	temp = this->_grade;
	temp = temp - num;
	try
	{
		if (temp < HIGHEST_GRADE)
			throw Bureaucrat::GradeTooHighException();
		this->_grade = this->_grade - num;
		std::cout << BOLD_GREEN << this->_name << " is promoted to grade "
					<< this->_grade << "!!" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/* Decrementing a grade 3 will give a grade 4 */
/* PS: is minus because num contains a minus */
/* Minus minus gives a plus */
void Bureaucrat::decrementGrade(int num)
{
	int	temp = this->_grade;
	temp = temp - num;
	try
	{
		if (temp > LOWEST_GRADE)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = this->_grade - num;
		std::cout << BOLD_RED << this->_name << " is demoted to grade "
				<< this->_grade << "!!" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/* Provides the definition of what() */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (BOLD_GREEN "Grade is too high." RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "Grade is too low." RESET);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}
