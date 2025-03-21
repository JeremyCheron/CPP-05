/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:01:25 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/21 08:55:52 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout
		<< BLUE
		<< "Bureaucrat Default Constructor called for "
		<< this->getName()
		<< " with level "
		<< this->getGrade()
		<< " grade!"
		<< RESET
		<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy")
{
	std::cout
		<< BLUE
		<< "Bureaucrat Copy Constructor called to copy "
		<< src.getName()
		<< " into "
		<< this->getName()
		<< "!"
		<< RESET
		<< std::endl;
		*this = src;
}

Bureaucrat::Bureaucrat(int grade): _name("default")
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout
		<< "Bureaucrat Constructor called for "
		<< this->getName()
		<< " with level "
		<< grade
		<< " grade!"
		<< RESET
		<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout
		<< BLUE
		<< "Bureaucrat Constructor called for "
		<< this->getName()
		<< " with level "
		<< this->getGrade()
		<< "!"
		<< RESET
		<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout
		<< BLUE
		<< "Bureaucrat Constructor called for "
		<< this->getName()
		<< " with level "
		<< grade
		<< "!"
		<< RESET
		<< std::endl;
		this->setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout
		<< RED
		<< "Bureaucrat Deconstructor called for "
		<< this->getName()
		<< "!"
		<< RESET
		<< std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout
		<< YELLOW
		<< "Bureaucrat Assignation operator called"
		<< RESET
		<< std::endl;
		if (this == &src)
			return *this;
		this->_grade = src.getGrade();
		return *this;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout
		<< GREEN
		<< "Trying to increment "
		<< this->getName()
		<< "'s grade!"
		<< RESET
		<< std::endl;
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout
		<< GREEN
		<< "Trying to decrement "
		<< this->getName()
		<< "'s grade!"
		<< RESET
		<< std::endl;
	this->setGrade(this->_grade + 1);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

size_t	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}
