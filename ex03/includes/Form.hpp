/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:02:34 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/22 12:35:44 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "colors.hpp"

class Bureaucrat;

class Form {

	protected:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
		Form();
		virtual void		_executeConcrete() const = 0;
	public:
		Form(const std::string &name, const std::string &target,
			int signGrade, int execGrade);
		Form(const Form &src);
		~Form();

		Form &operator=(const Form &src);

		const std::string	&getName() const;
		const std::string	&getTarget() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(const Bureaucrat &b);
		void				execute(const Bureaucrat &executor) const;

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form &a);
