/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:13:08 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/22 12:21:05 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

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

int main() {
	Bureaucrat	toto("Toto", 42);
	std::cout << toto << std::endl;

	sectionTitle("         Constructors");
	try {
		Form	form("Form", 1000, 1);
	} catch (std::exception &e) {
		print_error(e);
	}
	try {
		Form	form("Form", 1, 0);
	} catch (std::exception &e) {
		print_error(e);
	}

	try {
		Form	form("Form", 42, 42);

		std::cout << form << std::endl;

		sectionTitle("          sign twice");
		toto.signForm(form);
		std::cout << form << std::endl;
		toto.signForm(form);
	} catch (std::exception &e) {
		print_error(e);
	}

	sectionTitle("    sign with wrong grade");
	try {
		Form	form("Form", 1, 1);
		toto.signForm(form);
	} catch (std::exception &e) {
		print_error(e);
	}
}
