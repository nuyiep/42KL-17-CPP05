/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:10:01 by plau              #+#    #+#             */
/*   Updated: 2023/07/11 12:39:38 by plau             ###   ########.fr       */
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
				<< this->_grade << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/* Provides the definition of what() */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (BOLD_GREEN "[Bureaucrat]Grade too high." RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "[Bureaucrat] Grade too low." RESET);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}

Bureaucrat::Bureaucrat(std::string name, int grade) :_name(name)
{
	this->_grade = grade;
	try
	{
		if (grade > LOWEST_GRADE)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < HIGHEST_GRADE)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(2);
	}
}

void	Bureaucrat::signForm(AForm &Aform)
{
	try
	{
		if (Aform.getSigned() == true)
			std::cout << BOLD_MAGENTA << this->_name << " signed "
				<< Aform.getName() << RESET << std::endl;
		else
		{
			std::cout << BOLD_RED << this->_name << " couldn't sign "
				<< Aform.getName() << " because "<< RESET;
			throw AForm::GradeTooLowException();
		}
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	if (this->_grade < form.getExecuteGrade())
		std::cout << BOLD_MAGENTA << this->_name << " executed " << form.getName() << RESET << std::endl;
	else
		std::cout << BOLD_RED << this->_name << " failed to execute " << form.getName() << RESET << std::endl;
}
