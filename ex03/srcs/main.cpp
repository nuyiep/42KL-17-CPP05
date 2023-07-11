/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:26:58 by plau              #+#    #+#             */
/*   Updated: 2023/07/11 19:30:58 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* A is valid, B is invalid */
int main()
{
	int	gradeOne = 4;
	int	gradeTwo = 1;
	Bureaucrat BureauA("Nadjib", gradeOne);
	Bureaucrat BureauB("Angela Merkel", gradeTwo);
	Intern internA;
	
	std::cout << "\n---------- Shrubbery Test ----------\n" << std::endl;
	ShrubberyCreationForm ShrubA;
	ShrubberyCreationForm ShrubB("Deadpool");
	
	std::cout << ShrubA << std::endl;
	std::cout << ShrubB << std::endl;
	std::cout << BureauA << std::endl;
	std::cout << BureauB << std::endl;
	internA.makeForm(ShrubA.getName(), "Queen");
	ShrubA.performAction();
	ShrubA.beSigned(BureauA);
	BureauA.signForm(ShrubA);
	BureauA.executeForm(ShrubA);
	// internA.makeForm(ShrubB.getName(), "Queen II");
	// ShrubB.performAction();
	// ShrubB.beSigned(BureauB);
	// BureauB.signForm(ShrubB);
	// BureauB.executeForm(ShrubB);
	
	std::cout << "\n---------- Robotomy Test ----------\n" << std::endl;
	RobotomyRequestForm RobotA;
	RobotomyRequestForm RobotB("Kingsman");
	
	std::cout << RobotA << std::endl;
	std::cout << RobotB << std::endl;
	internA.makeForm(RobotA.getName(), "King Charles");
	RobotA.performAction();
	RobotA.beSigned(BureauA);
	BureauA.signForm(RobotA);
	BureauA.executeForm(RobotA);
	// internA.makeForm(RobotB.getName(), "Alexander the Great");
	// RobotB.performAction();
	// RobotB.beSigned(BureauB);
	// BureauB.signForm(RobotB);
	// BureauB.executeForm(RobotB);

	std::cout << "\n---------- Presidential Test ----------\n" << std::endl;
	PresidentialPardonForm PresidentA;
	PresidentialPardonForm PresidentB("Queen Elizabeth II");
	
	std::cout << PresidentA << std::endl;
	std::cout << PresidentB << std::endl;
	std::cout << BureauA << std::endl;
	std::cout << BureauB << std::endl;
	internA.makeForm(PresidentA.getName(), "Target1");
	PresidentA.performAction();
	PresidentA.beSigned(BureauA);
	BureauA.signForm(PresidentA);
	BureauA.executeForm(PresidentA);
	// internA.makeForm(PresidentB.getName(), "Target2");
	// PresidentB.performAction();
	// PresidentB.beSigned(BureauB);
	// BureauB.signForm(PresidentB);
	// BureauB.executeForm(PresidentB);
}
