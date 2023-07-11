/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:01:11 by plau              #+#    #+#             */
/*   Updated: 2023/07/11 20:54:50 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &src)
{
	(*this) = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

const char* Intern::FormDoesntExistException::what() const throw()
{
	return (BOLD_RED "Form doesn't exist." RESET);
}

/* Condensing the simple version below */
/* To avoid using a if/elseif/else forest */
AForm	*Intern::makeForm(std::string formName, std::string target)
{
	std::string formNameArray[3] =
	{
		"Shrubbery Creation Form",
		"Robotomy Request Form",
		"Presidential Pardon Form",
	};
	AForm *funcArray[3] = //Array of 3 pointers to base class objects
	{
		funcArray[0] = new ShrubberyCreationForm(target),
		// assigning a new ShrubberyCreationForm object to funcArray[0]
		// using the new operator to dynamically allocate memory for a Shrubbery object
		// and returns a pointer to it
		funcArray[1] = new RobotomyRequestForm(target),
		funcArray[2] = new PresidentialPardonForm(target),	
	};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formName == formNameArray[i])
			{
				std::cout << "Intern creates " << formName << std::endl;
				delete (funcArray[i]);
				return (nullptr);
			}
			else
				delete (funcArray[i]);	
		}
		throw FormDoesntExistException();
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD_RED << "[Intern] " << formName << " " << RESET;
		std::cerr << e.what() << '\n';
		for (int i = 0; i < 3; i++)
			delete funcArray[i];
		exit(3);
	}
	return (nullptr);
}

/* Simple version */
// Form* Intern::makeForm(const std::string formName, const std::string target)
// {
//     if (formName == "ShrubberyCreation")
//     {
//         std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
//         return new ShrubberyCreationForm(target);
//     }
//     else if (formName == "RobotomyRequest")
//     {
//         std::cout << "Intern creates RobotomyRequestForm" << std::endl;
//         return new RobotomyRequestForm(target);
//     }
//     else if (formName == "PresidentialPardon")
//     {
//         std::cout << "Intern creates PresidentialPardonForm" << std::endl;
//         return new PresidentialPardonForm(target);
//     }
    
//     std::cerr << "Error: Invalid form name" << std::endl;
//     return nullptr;
// }

