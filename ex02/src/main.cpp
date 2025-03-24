/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:13:08 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/24 07:24:53 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

void	sectionTitle(const std::string &title) {
	std::cout
		<< std::endl
		<< YELLOW
		<< "============================== "
		<< std::endl
		<< title
		<< std::endl
		<< "============================== "
		<< std::endl
		<< RESET
		<< std::endl
		<< std::endl;
}

void	print_error(std::exception &e) {
	std::cerr
		<< RED
		<< "Error: "
		<< e.what()
		<< RESET
		<< std::endl;
}

void	testForm(const Bureaucrat &b, Form &form) {
	std::cout << form << std::endl;
	b.signForm(form);
	b.execForm(form);
}

int main() {
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	toto("Toto", 42);
	std::cout << toto << std::endl;
	try {
		{
			sectionTitle("robotomy request form");
			RobotomyRequestForm	form("jcheron");
			testForm(boss, form);
		}
		{
			sectionTitle("shrubbery creation form");
			ShrubberyCreationForm	form("jcheron");
			testForm(boss, form);
		}
		{
			sectionTitle("presidential pardon form");
			PresidentialPardonForm	form("jcheron");
			testForm(boss, form);
		}
		PresidentialPardonForm	form("jcheron");
		{
			sectionTitle("Execute unsigned form");
			std::cout << form << std::endl;
			boss.execForm(form);
		}
		{
			sectionTitle("Try to execute a form with a too low grade");
			std::cout << form << std::endl;
			boss.signForm(form);
			toto.execForm(form);
		}
	} catch (std::exception &e) {
		print_error(e);
	}
}
