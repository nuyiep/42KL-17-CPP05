/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:14:44 by plau              #+#    #+#             */
/*   Updated: 2023/07/10 23:22:31 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		/* Orthodox canonical form */
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);		
		
		/* Required by PDF */
		ShrubberyCreationForm(const std::string target);
		void	performAction() const;
	private:
		std::string	_target;
};

#endif
