/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:02:10 by jcheron           #+#    #+#             */
/*   Updated: 2025/03/22 11:59:12 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"
#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat
{
	private:
		const std::string	_name;
		size_t				_grade;
		Bureaucrat();

	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &src);

		const std::string	&getName() const;
		int					getGrade() const;

		void				incrementGrade(int change = 1);
		void				decrementGrade(int change = 1);

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &o, Bureaucrat &a);
