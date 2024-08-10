/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:17:17 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 15:08:41 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class AForm{
	protected:
		std::string myTarget;
	
	private:
		const std::string name;
		bool signature;
		const int gradeS;
		const int gradeE;

	public:
		AForm();
		AForm(std::string n, bool s, int gs, int ge);
		AForm(const AForm &);
		AForm & operator = (const AForm &);
		virtual ~AForm();
		std::string getName() const;
		bool getSig() const;
		int getGradeSig() const;
		int getGradeExe() const;
		void beSigned(Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class NotSigned : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream & operator << (std::ostream &out, AForm &f);