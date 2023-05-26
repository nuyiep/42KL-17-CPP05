/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:10:01 by plau              #+#    #+#             */
/*   Updated: 2023/05/16 20:27:05 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->_grade = 0;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	(*this) = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/* Since grade 1 is the highest and 150 is the lowest */
/* incrementing a grade 3 will give a grade 2 */
void Bureaucrat::incrementGrade(int num)
{
	int	temp = this->_grade;
	temp = temp - num;
	if (errorCheckGrade(temp) == 1)
		this->_grade = this->_grade - num;
}

/* Decrementing a grade 3 will give a grade 4 */
void Bureaucrat::decrementGrade(int num)
{
	int	temp = this->_grade;
	temp = temp + num;
	if (errorCheckGrade(temp) == 1)
		this->_grade = this->_grade + num;
}

int Bureaucrat::errorCheckGrade(int temp)
{
	if (temp < 1)
	{
		std::cout << "Bureaucrat::GradeTooLowException" << std::endl;
		return (0);
	}
	else if (temp > 150)
	{
		std::cout << "Bureaucrat::GradeTooHighException" << std::endl;
		return (0);
	}
	return (1);
}