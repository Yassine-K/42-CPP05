/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:12:54 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 12:08:03 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat{
	private:
		const std::string name;
		int grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int val);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat &);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void gradeIncr();
		void gradeDecr();
		void signForm(Form *f);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "The grade is too High!";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "The grade is too Low!";
				}
		};
};

std::ostream & operator<<(std::ostream &out, const Bureaucrat &b);