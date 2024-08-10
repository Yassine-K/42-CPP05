/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:15:59 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 15:01:42 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat() {
	
}

Bureaucrat::Bureaucrat(const std::string n, int val) : name(n) {
	if (val < 1)
		throw GradeTooHighException();
	else if (val > 150)
		throw GradeTooLowException();
	grade = val;
}

Bureaucrat::Bureaucrat(const Bureaucrat & copy) : name(copy.name) {
	grade = copy.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & bureau) {
	if (this != &bureau) {
		grade = bureau.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	
}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const{
	return grade;
}

void Bureaucrat::gradeIncr() {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::gradeDecr() {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream & operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() <<", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade is too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too Low!";
}