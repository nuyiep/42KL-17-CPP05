/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:55:48 by plau              #+#    #+#             */
/*   Updated: 2023/07/10 23:48:35 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :AForm("Robotomy", 72, 45)
{
	this->_target = "Home";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	(*this) = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->_target = src._target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(target, 72, 45)
{
	this->_target = target;
}

/* srand - initialize random number generators */
/* 		 - sets the starting point for producing a series of pseudo-random integers */
/* 		 - argument can be of any unsigned int */
void	RobotomyRequestForm::performAction() const
{
	std::cout << BOLD_MAGENTA "~* Drilling noise ~*" RESET << std::endl;
	srand(time(nullptr));
	if (rand() % 2 == 0)
		std::cout << BOLD_BLUE << this->_target << " has been robotomized successfully [Random]" RESET << std::endl;
	else
		std::cout << BOLD_RED << this->_target << "'s robotomy failed [Random]" RESET << std::endl;
}
