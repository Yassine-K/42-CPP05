/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:46:03 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 15:06:55 by ykhayri          ###   ########.fr       */
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
		std::string getName() const;
		bool getSig() const;
		int getGradeSig() const;
		int getGradeExe() const;
		void beSigned(Bureaucrat &b);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream & operator << (std::ostream &out, Form &f);