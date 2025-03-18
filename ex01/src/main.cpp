/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:01:04 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/18 12:48:07 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	{
		std::cout
			<< MAGENTA
			<< "Constructors"
			<< RESET
			<< std::endl;
			Bureaucrat *a = new Bureaucrat();
			Form *b = new Form();
		std::cout
			<< MAGENTA
			<< "Tests"
			<< RESET
			<< std::endl;
		std::cout << a;
		std::cout << b;
		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr
				<< RED
				<< a->getName()
				<< " wasn't able to sign "
				<< b->getName()
				<< ": "
				<< e.what()
				<< RESET
				<< std::endl;
		}
		std::cout << b;
		std::cout
			<< MAGENTA
			<< "Deconstructors"
			<< RESET
			<< std::endl;
		delete a;
		delete b;
	}
	std::cout << "------------------------------------------" << std::endl;
	{
		std::cout
			<< MAGENTA
			<< "Constructors"
			<< RESET
			<< std::endl;
			Bureaucrat *a = new Bureaucrat();
			Bureaucrat *c = new Bureaucrat("Boss", 1);
			Form *b = new Form(140, 100);
		std::cout
			<< MAGENTA
			<< "Tests"
			<< RESET
			<< std::endl;
		std::cout << a;
		std::cout << c;
		std::cout << b;
		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr
				<< RED
				<< a->getName()
				<< " wasn't able to sign "
				<< b->getName()
				<< ": "
				<< e.what()
				<< RESET
				<< std::endl;
		}
		try
		{
			b->beSigned(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr
				<< RED
				<< c->getName()
				<< " wasn't able to sign "
				<< b->getName()
				<< ": "
				<< e.what()
				<< RESET
				<< std::endl;
		}
		std::cout << b;
		std::cout << c;
		std::cout
			<< MAGENTA
			<< "Deconstructors"
			<< RESET
			<< std::endl;
		delete a;
		delete b;
		delete c;
	}
}
