/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:26:58 by plau              #+#    #+#             */
/*   Updated: 2023/07/10 17:16:43 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm ShrubA;
	ShrubberyCreationForm ShrubB("Deadpool");
	RobotomyRequestForm RobotA;
	RobotomyRequestForm RobotB("Kingsman");
	PresidentialPardonForm PresidentA;
	PresidentialPardonForm PresidentB("Queen Elizabeth II");

	std::cout << "\n---------- Shrubbery Test ----------\n" << std::endl;
	std::cout << ShrubA << std::endl;
	std::cout << ShrubB << std::endl;
	ShrubA.drawTree();

	std::cout << "\n---------- Robotomy Test ----------\n" << std::endl;
	std::cout << RobotA << std::endl;
	std::cout << RobotB << std::endl;
	RobotA.performAction();

	std::cout << "\n---------- Presidential Test ----------\n" << std::endl;
	std::cout << PresidentA << std::endl;
	std::cout << PresidentB << std::endl;
}
