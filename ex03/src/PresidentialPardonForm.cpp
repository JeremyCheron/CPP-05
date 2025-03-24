/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:30:27 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/22 12:38:29 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): Form() {}

PresidentialPardonForm::PresidentialPardonForm(
		const std::string &target)
	: Form("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
		const PresidentialPardonForm &src): Form() {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
		const PresidentialPardonForm &src) {
	if (this != &src) {}
	return *this;
}

void	PresidentialPardonForm::_executeConcrete() const {
	std::cout
		<< "Tells us " << getTarget()
		<< " has been pardoned by Zafod Beeblebrox."
		<< std::endl;
}
