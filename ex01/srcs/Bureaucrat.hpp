/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:09:40 by plau              #+#    #+#             */
/*   Updated: 2023/07/07 16:54:09 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "color.hpp"
#include "Form.hpp"

# define HIGHEST_GRADE 	1
# define LOWEST_GRADE 	150

class Form;
class Bureaucrat
{
	public:
		/* Orthodox canonical form */
		Bureaucrat(); //default constructor
		~Bureaucrat(); //destructor
		Bureaucrat(const Bureaucrat &src); //copy constructor
		Bureaucrat& operator=(const Bureaucrat &src); //assignment operator

		/* Required by PDF */
		std::string	const & getName() const;
		int					getGrade() const;
		void				incrementGrade(int num);
		void				decrementGrade(int num);
		void				signForm(Form &form);

		/* Member functions */
		Bureaucrat(std::string name, int grade);

		/* Exception classes */
		/* Inherited from std::exception class */
		/* can be caught by a catch block that catches std""exception objects" */
		/* Declares a member function what(), overrides the what() */
		/* function defined in std::exception - using virtual */ 
		/* throw- indicate that a function will not throw any exceptions */
		/* and it allows for more efficient exception handling */
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();	
		};
		
	private:
		const	std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj);

#endif
