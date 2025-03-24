/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:13:08 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/24 09:48:25 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"

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

Bureaucrat burro("Burro", 1);
Intern 	intern;

void testMake(const std::string &formName, const std::string &target) {
	sectionTitle("Test " + formName);
	Form *form = intern.makeForm(formName, target);

	std::cout << *form << std::endl;
	burro.signForm(*form);
	burro.execForm(*form);
}

int main() {
	try {
		testMake("shrubbery creation", "jcheron");
		testMake("robotomy request", "Bender");
		testMake("presidential pardon", "jcheron");
		testMake("unknown", "jcheron");
	} catch (std::exception &e) {
		print_error(e);
	}
}
