/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:26:58 by plau              #+#    #+#             */
/*   Updated: 2023/07/11 00:09:23 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat BureauA("Nadjib", 150);
	Bureaucrat BureauB("Angela Merkel", 0);
	Bureaucrat BureauC("Winston Churchill", 140);

	std::cout << "\n---------- Shrubbery Test ----------\n" << std::endl;
	ShrubberyCreationForm ShrubA;
	ShrubberyCreationForm ShrubB("Deadpool");
	ShrubberyCreationForm ShrubC("Enigma");
	
	std::cout << ShrubA << std::endl;
	std::cout << ShrubB << std::endl;
	std::cout << ShrubC << std::endl;
	std::cout << BureauA << std::endl;
	std::cout << BureauB << std::endl;
	std::cout << BureauC << std::endl;
	ShrubA.performAction();
	ShrubA.beSigned(BureauA);
	BureauA.signForm(ShrubA);
	BureauA.executeForm(ShrubA);
	ShrubB.performAction();
	ShrubB.beSigned(BureauB);
	BureauB.signForm(ShrubB);
	BureauB.executeForm(ShrubB);
	ShrubC.performAction();
	ShrubC.beSigned(BureauC);
	BureauC.signForm(ShrubC);
	BureauC.executeForm(ShrubC);
	
	std::cout << "\n---------- Robotomy Test ----------\n" << std::endl;
	RobotomyRequestForm RobotA;
	RobotomyRequestForm RobotB("Kingsman");
	RobotomyRequestForm RobotC("ChatGPT");
	Bureaucrat BureauD("Martin Luther", 70);
	
	std::cout << RobotA << std::endl;
	std::cout << RobotB << std::endl;
	std::cout << RobotC << std::endl;
	std::cout << BureauA << std::endl;
	std::cout << BureauB << std::endl;
	std::cout << BureauD << std::endl;
	RobotA.performAction();
	RobotA.beSigned(BureauA);
	BureauA.signForm(RobotA);
	BureauA.executeForm(RobotA);
	RobotB.performAction();
	RobotB.beSigned(BureauB);
	BureauB.signForm(RobotB);
	BureauB.executeForm(RobotB);
	RobotC.performAction();
	RobotC.beSigned(BureauD);
	BureauD.signForm(RobotC);
	BureauD.executeForm(RobotC);

	std::cout << "\n---------- Presidential Test ----------\n" << std::endl;
	PresidentialPardonForm PresidentA;
	PresidentialPardonForm PresidentB("Queen Elizabeth II");
	Bureaucrat BureauE("Rishi Sunak", 20);
	
	std::cout << PresidentA << std::endl;
	std::cout << PresidentB << std::endl;
	std::cout << BureauA << std::endl;
	std::cout << BureauB << std::endl;
	std::cout << BureauE << std::endl;
	PresidentA.performAction();
	PresidentA.beSigned(BureauA);
	BureauA.signForm(PresidentA);
	BureauA.executeForm(PresidentA);
	PresidentB.performAction();
	PresidentB.beSigned(BureauB);
	BureauB.signForm(PresidentB);
	BureauB.executeForm(PresidentB);
	PresidentB.performAction();
	PresidentB.beSigned(BureauE);
	BureauE.signForm(PresidentB);
	BureauE.executeForm(PresidentB);
}
