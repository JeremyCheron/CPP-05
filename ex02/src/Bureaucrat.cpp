/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:01:25 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/22 13:59:18 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name),
	_grade(grade)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name),
	_grade(src._grade)
{}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src)
		_grade = src._grade;
	return *this;
}

const std::string	&Bureaucrat::getName() const {
	return _name;
}

int					Bureaucrat::getGrade() const {
	return _grade;
}

void				Bureaucrat::incrementGrade(int change) {
	if (_grade - change < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade -= change;
}

void				Bureaucrat::decrementGrade(int change) {
	if (_grade + change > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade += change;
}

void				Bureaucrat::signForm(Form &f) const {
	try {
		f.beSigned(*this);
		std::cout
			<< _name
			<< " signs "
			<< f.getName()
			<< std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout
			<< RED
			<< _name
			<< " cannot sign "
			<< f.getName()
			<< " because his grade is too low"
			<< RESET
			<< std::endl;
	}
}

void				Bureaucrat::execForm(Form &f) const {
	try {
		f.execute(*this);
		std::cout
			<< _name
			<< " executes "
			<< f.getName()
			<< std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout
			<< RED
			<< _name
			<< " cannot execute "
			<< f.getName()
			<< " because his grade is too low"
			<< RESET
			<< std::endl;
	} catch (Form::NotSignedException &e) {
		std::cout
			<< RED
			<< _name
			<< " cannot execute "
			<< f.getName()
			<< " because the form is not signed"
			<< RESET
			<< std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return RED "Bureaucrat grade too high !" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return RED "Bureaucrat grade too low !" RESET;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &a) {
	o
		<< a.getName()
		<< ", bureaucrat of grade "
		<< a.getGrade()
		<< std::endl;
	return o;
}
