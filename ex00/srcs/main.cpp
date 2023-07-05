/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:09:30 by plau              #+#    #+#             */
/*   Updated: 2023/07/05 15:50:42 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	int	grade;

	grade = 0;
	std::cout << BOLD_GREEN ".......Test case 01- default......" RESET << std::endl;
	Bureaucrat	bureaucratA;
	std::cout << "Lowest grade is 150" << std::endl;
	std::cout << "Highest grade is 0" << std::endl;
	std::cout << "Default bureacrat: " << bureaucratA << std::endl;
	std::cout << "Increment/decrement grade (+/- number): " << std::endl;
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
	std::cout << "Increment/decrement grade (+/- number): " << std::endl;
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
}
