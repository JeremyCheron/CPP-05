/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:22:06 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/24 07:23:34 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form() {}

RobotomyRequestForm::RobotomyRequestForm(
		const std::string &target)
	: Form("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(
		const RobotomyRequestForm &src): Form() {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
		const RobotomyRequestForm &src) {
	if (this != &src) {}
	return *this;
}

void	RobotomyRequestForm::_executeConcrete() const {
	std::cout
		<< "Drilling noises... "
		<< getTarget()
		<< " has been robotomized successfully 50\% of the time."
		<< std::endl;
}
