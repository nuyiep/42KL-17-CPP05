/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:16:48 by plau              #+#    #+#             */
/*   Updated: 2023/07/05 20:58:46 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
	this->_signed = false;
}

Form::~Form()
{
}

Form::Form(const Form &src)
{
	(*this) = src;
}

Form &Form::operator=(const Form &src)
{
	
}
