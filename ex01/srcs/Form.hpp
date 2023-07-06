/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:51 by plau              #+#    #+#             */
/*   Updated: 2023/07/06 13:20:12 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

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
		std::string		   &getName() const;
		bool			   	getSigned() const;
		int				    getSignGrade() const;
		const int					getExecuteGrade();
		

	private:
		const std::string 	_name;
		bool 				_signed;
		const int 			_signGrade;
		const int 			_executeGrade;
};

std::ostream &operator<<(std::ostream &os, Form const &obj);

#endif
