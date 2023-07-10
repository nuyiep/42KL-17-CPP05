/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:14:51 by plau              #+#    #+#             */
/*   Updated: 2023/07/10 20:36:23 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	this->_target = "Home";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	(*this) = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->_target = src._target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :AForm(target, 145, 137)
{
	this->_target = target;
}

void	ShrubberyCreationForm::performAction()
{
	std::ofstream	outFile(this->_target + "_shrubbery");
	 
	outFile << "                         #\n";
	outFile << "                       ## ##\n";
	outFile << "                     #### ###\n";
	outFile << "                  # #### ####\n";
    outFile << "                ### /#|### |/####\n";
    outFile << "               ##/#/  ||/##/_/##/_#\n";
    outFile << "             ###  /###|/  / # ###\n";
	outFile << "           ##__#_  ## | #/###_/_####\n";
	outFile << "          ## #### #   #| /  #### ##/##\n";
    outFile << "           __#_--###`  ||,###---###-~\n";
    outFile << "                       ||\n";
    outFile << "                      |||\n";
    outFile << "                      |||\n";
	outFile << "                      |||\n";
    outFile << "                , -=-~| .-^- _ \n";
	outFile.close();
	std::cout << BOLD_MAGENTA << this->_target << "_shrubbery file has been created- ascii tree is in the file" RESET << std::endl;
}
