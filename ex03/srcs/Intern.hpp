/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:01:04 by plau              #+#    #+#             */
/*   Updated: 2023/07/11 16:28:46 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		/* Orthodox canonical form */
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern& operator=(const Intern &src);

		/* Required by the PDF */
		AForm	*makeForm(std::string formName, std::string target);

		/* Exception classes */
		class FormDoesntExistException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
};

#endif
