/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:17:01 by plau              #+#    #+#             */
/*   Updated: 2023/07/11 00:04:28 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :AForm("Presidential Form 1", 25, 5)
{
	this->_target = "42";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
	(*this) = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->_target = src._target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :AForm("Presidential Form 2", 25, 5)
{
	this->_target = target;
}

void	PresidentialPardonForm::performAction() const
{
	std::cout << BOLD_MAGENTA << this->_target << " has been pardoned by Zaphod Beeblebrox"<< RESET << std::endl;
}
