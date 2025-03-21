/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:01:04 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/21 09:00:30 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	try {
		std::cout
			<< MAGENTA
			<< "Creating Bureaucrat with a valid grade\n"
			<< RESET
			<< std::endl;
		Bureaucrat b1("Alice", 42);
	} catch (std::exception &e) {
		std::cerr
			<< RED
			<< "Error: "
			<< e.what()
			<< RESET
			<< std::endl;
	}

	try {
		std::cout
			<< MAGENTA
			<< "\nCreating Bureaucrat with a too high grade\n"
			<< RESET
			<< std::endl;
		Bureaucrat b2("Bob", 0);
	} catch (std::exception &e) {
		std::cerr
			<< RED
			<< "Error: "
			<< e.what()
			<< RESET
			<< std::endl;
	}

	try {
		std::cout
			<< MAGENTA
			<< "\nCreating Bureaucrat with a too low grade\n"
			<< RESET
			<< std::endl;
		Bureaucrat b3("Charlie", 151);
	} catch (std::exception &e) {
		std::cerr
			<< RED
			<< "Error: "
			<< e.what()
			<< RESET
			<< std::endl;
	}

	try {
		std::cout
			<< MAGENTA
			<< "\nTesting grade increment\n"
			<< RESET
			<< std::endl;
		Bureaucrat b4("David", 2);
		std::cout << &b4 << std::endl;
		b4.incrementGrade();
		std::cout << &b4 << std::endl;
		b4.incrementGrade();
	} catch (std::exception &e) {
		std::cerr
			<< RED
			<< "Error: "
			<< e.what()
			<< RESET
			<< std::endl;
	}

	try {
		std::cout
			<< MAGENTA
			<< "\nTesting grade decrement\n"
			<< RESET
			<< std::endl;
		Bureaucrat b5("Eve", 149);
		std::cout << &b5 << std::endl;
		b5.decrementGrade();
		std::cout << &b5 << std::endl;
		b5.decrementGrade();
	} catch (std::exception &e) {
		std::cerr
			<< RED
			<< "Error: "
			<< e.what()
			<< RESET
			<< std::endl;
	}
	return 0;
}
