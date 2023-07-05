/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:09:30 by plau              #+#    #+#             */
/*   Updated: 2023/07/05 17:20:50 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	int			grade;
	std::string name;

	grade = 0;
	std::cout << BOLD_GREEN ".......Test case 01- default......" << std::endl;
	Bureaucrat	bureaucratA;
	std::cout << "Lowest grade is 150" << std::endl;
	std::cout << "Highest grade is 0" RESET << std::endl;
	std::cout << "Default bureacrat: " << bureaucratA << std::endl;
	std::cout << "Increment/decrement grade (+/- number): ";
	std::cin >> grade;
	try
	{
		if (grade > 0)
			bureaucratA.incrementGrade(grade);
		else if (grade < 0)
			bureaucratA.decrementGrade(grade);
		else
			return (1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << BOLD_GREEN ".......Test case 02- copy constructor......." RESET << std::endl;
	Bureaucrat bureaucratB(bureaucratA);
	std::cout << "BureaucratB: " << bureaucratB << std::endl;
	std::cout << "Increment/decrement grade (+/- number): ";
	std::cin >> grade;
	try
	{
		if (grade > 0)
			bureaucratB.incrementGrade(grade);
		else if (grade < 0)
			bureaucratB.decrementGrade(grade);
		else
			return (1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << BOLD_GREEN ".......Test case 03- name and grade constructor......." RESET << std::endl;
	while (1)
	{
		std::cout << "Enter bureaucrat name: ";
		std::cin >> name;
		std::cout << "Enter grade: ";
		std::cin >> grade;
		if (grade == 0)
		{
			std::cerr << "Invalid input" << std::endl;
			return (3);
		}
		try
		{
			Bureaucrat bureaucratC(name, grade);
			std::cout << "BureaucratC: " << bureaucratC << std::endl;
			std::cout << "Increment/decrement grade (+/- number): ";
			std::cin >> grade;
			if (grade > 0)
				bureaucratC.incrementGrade(grade);
			else if (grade < 0)
				bureaucratC.decrementGrade(grade);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return (2);
		}
	}
}
