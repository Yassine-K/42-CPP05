/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:55:18 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 10:53:58 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name(""), gradeS(150), gradeE(150) {
}

Form::Form(std::string n, bool s, int gs, int ge) : name(n), signature(s), gradeS(gs), gradeE(ge){
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	else if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

Form::Form(const Form & copy) : name(copy.name), signature(copy.signature), gradeS(copy.gradeS), gradeE(copy.gradeE){
}

Form & Form::operator = (const Form &copy){
	if (this != &copy)
		signature = copy.signature;
	return *this;
}

Form::~Form(){
}

std::string Form::getName() const {
	return name;
}

bool Form::getSig() const {
	return signature;
}

int Form::getGradeSig() const {
	return gradeS;
}

int Form::getGradeExe() const {
	return gradeE;
}

void Form::beSigned(Bureaucrat &b){
	if (b.getGrade() > gradeS){
		throw (GradeTooLowException());
		}
	signature = true;
}

std::ostream & operator << (std::ostream &out, Form &f){
	std::cout << "Form name: " << f.getName() << " is signed: " << f.getSig() << " must have a grade of " << f.getGradeSig() << " to sign it and a grade of " << f.getGradeExe() << " to execute it" << std::endl;
	return out;
}