/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:01:04 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/22 12:00:27 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

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

int main() {
	sectionTitle("         Constructors");

	try {
		Bureaucrat	Toto("Toto", 1);
		std::cout << Toto << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat Titi("Titi", -42);
		std::cout << Titi << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat	Tutu("Tutu", 4242);
		std::cout << Tutu << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	sectionTitle("    Increment / Decrement");

	try {
		Bureaucrat	Toto("Toto", 10);
		std::cout << Toto << std::endl;
		Toto.incrementGrade(8);
		std::cout << Toto << std::endl;
		Toto.incrementGrade();
		std::cout << Toto << std::endl;
		Toto.incrementGrade();
		std::cout << Toto << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat	Toto("Toto", 141);
		std::cout << Toto << std::endl;
		Toto.decrementGrade(8);
		std::cout << Toto << std::endl;
		Toto.decrementGrade();
		std::cout << Toto << std::endl;
		Toto.decrementGrade();
		std::cout << Toto << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
