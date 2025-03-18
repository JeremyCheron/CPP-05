/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:01:04 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/18 11:57:06 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	{
		std::cout
			<< MAGENTA
			<< "Constructor"
			<< RESET
			<< std::endl;
			Bureaucrat *a = new Bureaucrat();
		std::cout
			<< MAGENTA
			<< "Tests"
			<< RESET
			<< std::endl;
		std::cout << a;
		try
		{
			a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr
				<< RED
				<< "Incrementing grade of "
				<< a->getName()
				<< " failed: "
				<< e.what()
				<< RESET
				<< std::endl;
		}
		std::cout << a;
		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr
				<< RED
				<< "Decrementing grade of "
				<< a->getName()
				<< " failed: "
				<< e.what()
				<< RESET
				<< std::endl;
		}
		std::cout << a;
		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr
				<< RED
				<< "Decrementing grade of "
				<< a->getName()
				<< " failed: "
				<< e.what()
				<< RESET
				<< std::endl;
		}
		std::cout << a;
		std::cout
			<< MAGENTA
			<< "Deconstructor"
			<< RESET
			<< std::endl;
		delete a;
	}
}
