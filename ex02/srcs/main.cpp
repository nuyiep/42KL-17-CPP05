/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:26:58 by plau              #+#    #+#             */
/*   Updated: 2023/07/10 20:57:26 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat BureauA("Nadjib", 150);
	Bureaucrat BureauB("Angela Merkel", 1);
	ShrubberyCreationForm ShrubA;
	ShrubberyCreationForm ShrubB("Deadpool");
	RobotomyRequestForm RobotA;
	RobotomyRequestForm RobotB("Kingsman");
	PresidentialPardonForm PresidentA;
	PresidentialPardonForm PresidentB("Queen Elizabeth II");

	std::cout << "\n---------- Shrubbery Test ----------\n" << std::endl;
	std::cout << ShrubA << std::endl;
	std::cout << ShrubB << std::endl;
	ShrubA.performAction();
	ShrubB.performAction();
	BureauB.signForm(ShrubA);
	

	// std::cout << "\n---------- Robotomy Test ----------\n" << std::endl;
	// std::cout << RobotA << std::endl;
	// std::cout << RobotB << std::endl;
	// RobotA.performAction();
	// RobotB.performAction();

	// std::cout << "\n---------- Presidential Test ----------\n" << std::endl;
	// std::cout << PresidentA << std::endl;
	// std::cout << PresidentB << std::endl;
	// PresidentA.performAction();
	// PresidentB.performAction();
}
