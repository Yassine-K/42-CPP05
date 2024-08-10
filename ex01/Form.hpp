/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:46:03 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 10:11:39 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string name;
		bool signature;
		const int gradeS;
		const int gradeE;
	public:
		Form();
		Form(std::string n, bool s, int gs, int ge);
		Form(const Form &);
		Form & operator = (const Form &);
		~Form();
		std::string getName();
		bool getSig();
		int getGradeSig();
		int getGradeExe();
		void beSigned(Bureaucrat &b);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "The form's grade is too High!";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "The form's grade is too Low!";
				}
		};
};

std::ostream & operator << (std::ostream &out, Form &f);