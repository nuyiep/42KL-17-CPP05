/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:51 by plau              #+#    #+#             */
/*   Updated: 2023/07/07 16:18:39 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	public:
		/* Orthodox canonical form */
		Form(); //default constructor
		~Form(); //destructor
		Form(const Form &src); //copy constructor
		Form& operator=(const Form &src); //assignment operator

		/* Required by PDF */
		/* Getters - adding const behind- indicates that it */
		/* will not modify the state of the object  */
		/* but it allows the modification of the returned value */
		std::string		    getName() const;
		bool			   	getSigned() const;
		int				    getSignGrade() const;
		int					getExecuteGrade() const;
		
		/* Member functions */
		Form(std::string name, int signGrade, int executeGrade); //name and grade constructor
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
