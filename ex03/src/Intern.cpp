/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:40:06 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/24 09:42:59 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

const std::string	Intern::_names[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

const CF	Intern::_forms[3] = {
	&Intern::_createShrubbery,
	&Intern::_createRobotomy,
	&Intern::_createPresidential
};

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src) {
	if (this != &src) {}
	return *this;
}

Form	*Intern::makeForm(const std::string &name, const std::string &target) const {
	for (int i = 0; i < 3; i++) {
		if (name == _names[i]) {
			return (this->*_forms[i])(target);
		}
	}
	throw Intern::FormNotFoundException();
}

Form* Intern::_createShrubbery(const std::string &target) const {
	return new ShrubberyCreationForm(target);
}

Form* Intern::_createRobotomy(const std::string &target) const {
	return new RobotomyRequestForm(target);
}

Form* Intern::_createPresidential(const std::string &target) const {
	return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
	return RED "Form not found" RESET;
}
