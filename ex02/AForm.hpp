/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:51 by plau              #+#    #+#             */
/*   Updated: 2023/07/07 20:42:01 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	public:
		/* Orthodox canonical form */
		AForm(); //default constructor
		~AForm(); //destructor
		AForm(const AForm &src); //copy constructor
		AForm& operator=(const AForm &src); //assignment operator

		/* Required by PDF */
		/* Getters - adding const behind- indicates that it */
		/* will not modify the state of the object  */
		/* but it allows the modification of the returned value */
		std::string		    getName() const;
		bool			   	getSigned() const;
		int				    getSignGrade() const;
		int					getExecuteGrade() const;
		
		/* Member functions */
		AForm(std::string name, int signGrade, int executeGrade); //name and grade constructor
		void				beSigned(Bureaucrat bureaucrat);
		
		/* Exception classes */
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
		const std::string 	_name;
		bool 				_signed;
		const int 			_signGrade;
		const int 			_executeGrade;
};

std::ostream &operator<<(std::ostream &os, Form const &obj);

#endif
