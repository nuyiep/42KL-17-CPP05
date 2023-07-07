/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:25:25 by plau              #+#    #+#             */
/*   Updated: 2023/07/07 16:09:01 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	Form 		A;
	Form 		B(A);
	std::string name;
	int			signGrade;
	int			executeGrade;

	std::cout << std::endl << BOLD_BLUE "Test 1- Default constructor" << std::endl;
	std::cout << A;
	std::cout << BOLD_BLUE "Test 2- Copy constructor" << std::endl;
	std::cout << B;
	std::cout << BOLD_BLUE "Test 3- Name and grade constructor" RESET << std::endl;
	while (1)
	{
		std::cout << "Enter form name: (Only allow 1 word) ";
		std::cin >> name;
		std::cout << "Enter sign grade: ";
		std::cin >> signGrade;
		std::cout << "Enter execute grade: ";
		std::cin >> executeGrade;
		try
		{
			Form C(name, signGrade, executeGrade);
			Bureaucrat X("Elon", -1);
			std::cout << "Signor Info: " << X << std::endl;
			C.beSigned(X);
			std::cout << std::endl << C;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return (2);
		}
	}
}
