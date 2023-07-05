/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:51 by plau              #+#    #+#             */
/*   Updated: 2023/07/05 20:59:46 by plau             ###   ########.fr       */
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
		

	private:
		const std::string 	_name;
		bool 				_signed;
		const int 			_signGrade;
		const int 			_executeGrade;
};

#endif
