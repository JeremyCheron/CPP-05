/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:22:52 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/18 12:40:24 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout
		<< BLUE
		<< "Form Default Constructor called for "
		<< this->getName()
		<< "!"
		<< RESET
		<<std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout
		<< BLUE
		<< "Form Copy Constructor called to copy "
		<< src.getName()
		<< " into "
		<< this->getName()
		<< "!"
		<< RESET
		<< std::endl;
		*this = src;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout
		<< BLUE
		<< "Form Constructor called for "
		<< this->getName()
		<< " with level "
		<< sign_grade
		<< " sign grade and level "
		<< exec_grade
		<< " exec grade!"
		<< RESET
		<<std::endl;
		const int i = this->getSignGrade();
		const int j = this->getSignGrade();
		if (i > 150 || j > 150)
			throw(Form::GradeTooLowException());
		else if (i < 1 || j < 1)
			throw(Form::GradeTooHighException());
}

Form::~Form()
{
	std::cout
		<< RED
		<< "Form Descontructor called for "
		<< this->getName()
		<< "!"
		<< std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout
		<< YELLOW
		<< "Form Assignation operator called"
		<< RESET
		<< std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == "false")
	{
		this->_is_signed = true;
		std::cout
			<< GREEN
			<< this->getName()
			<< " Form was signed by "
			<< signer.getName()
			<< "!"
			<< RESET
			<< std::endl;
	}
	else
		std::cout
			<< RED
			<< this->getName()
			<< " Form is already signed!"
			<< RESET
			<< std::endl;
}

const std::string Form::getName(void) const
{
	return (this->_name);
}

const std::string Form::getIsSigned(void) const
{
	if (this->_is_signed)
		return ("true");
	return ("false");
}

bool Form::getIsSignedBool(void) const
{
	return (this->_is_signed);
}

int Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o
		<< "Form "
		<< a->getName()
		<< ":\n\tsign grade:\t"
		<< a->getSignGrade()
		<< ":\n\texec grade:\t"
		<< a->getExecGrade()
		<< ":\n\tis signed:\t"
		<< a->getIsSigned()
		<< std::endl;
	return (o);
}
