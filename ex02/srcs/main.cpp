/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:26:58 by plau              #+#    #+#             */
/*   Updated: 2023/07/10 16:09:16 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm ShrubA;
	ShrubberyCreationForm ShrubB(ShrubA);

	std::cout << "\n---------- EX02 Shrubbery Test ----------\n" << std::endl;
	std::cout << ShrubA << std::endl;
	std::cout << ShrubB << std::endl;
	ShrubA.drawTree();
}
