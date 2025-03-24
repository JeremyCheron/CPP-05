/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:36:09 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/24 09:42:04 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern;

typedef Form* (Intern::*CF)(const std::string&) const;

class Intern {
	private:
		static const CF				_forms[3];
		static const std::string	_names[3];

		Form* _createShrubbery(const std::string &target) const;
		Form* _createRobotomy(const std::string &target) const;
		Form* _createPresidential(const std::string &target) const;
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern &src);

		Form	*makeForm(const std::string &name, const std::string &target) const;

		class FormNotFoundException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
