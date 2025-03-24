/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:04:52 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/22 14:06:26 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

static void	checkGrade(int grade, int min = MIN_GRADE, int max = MAX_GRADE) {
	if (grade < max)
		throw Form::GradeTooHighException();
	else if (grade > min)
		throw Form::GradeTooLowException();
}

Form::Form(): _signGrade(1), _execGrade(1) {}

Form::Form(const std::string &name, const std::string &target,
	int signGrade, int execGrade)
	: _name(name),
	_target(target),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	checkGrade(signGrade);
	checkGrade(execGrade);
}

Form::Form(const Form &src)
	: _name(src._name),
	_signed(src._signed),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade)
{}

Form::~Form() {}

Form &Form::operator=(const Form &src) {
	if (this != &src) {}
	return *this;
}

const std::string	&Form::getName() const {
	return _name;
}

const std::string	&Form::getTarget() const {
	return _target;
}

bool				Form::isSigned() const {
	return _signed;
}

int					Form::getSignGrade() const {
	return _signGrade;
}

int					Form::getExecGrade() const {
	return _execGrade;
}

void				Form::beSigned(const Bureaucrat &b) {
	if (_signed)
		throw Form::AlreadySignedException();
	if (_signGrade < b.getGrade())
		throw Form::GradeTooLowException();
	_signed = true;
}

void				Form::execute(const Bureaucrat &executor) const {
	if (!_signed)
		throw Form::NotSignedException();
	if (_execGrade < executor.getGrade())
		throw Form::GradeTooLowException();
	_executeConcrete();
}

const char *Form::GradeTooHighException::what() const throw() {
	return RED "Form grade too high !" RESET;
}

const char *Form::GradeTooLowException::what() const throw() {
	return RED "Form grade too low !" RESET;
}

const char *Form::AlreadySignedException::what() const throw() {
	return RED "Form already signed !" RESET;
}

const char *Form::NotSignedException::what() const throw() {
	return RED "FormCannot execute unsigned Form!" RESET;
}

std::ostream &operator<<(std::ostream &o, Form &a) {
	o
		<< std::boolalpha
		<< "Form "
		<< a.getName()
		<< ", signed: "
		<< a.isSigned()
		<< ", grade to sign "
		<< a.getSignGrade()
		<< ", grade to execute "
		<< a.getExecGrade()
		<< std::endl;
	return o;
}
