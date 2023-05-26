/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:09:40 by plau              #+#    #+#             */
/*   Updated: 2023/05/16 20:24:22 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>

class Bureaucrat
{
	public:
		/* Orthodox canonical form */
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat& operator=(const Bureaucrat &src);

		/* Required by PDF */
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade(int num);
		void		decrementGrade(int num);

		/* Member functions */
		int			errorCheckGrade(int temp);
		
	private:
		const	std::string	_name;
		int					_grade;
};

#endif
