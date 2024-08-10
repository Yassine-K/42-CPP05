/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 08:55:18 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 10:23:07 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name(""), gradeS(150), gradeE(150) {
}

AForm::AForm(std::string n, bool s, int gs, int ge) : name(n), signature(s), gradeS(gs), gradeE(ge){
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	else if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm & copy) : name(copy.name), signature(copy.signature), gradeS(copy.gradeS), gradeE(copy.gradeE){
}

AForm & AForm::operator = (const AForm &copy){
	if (this != &copy)
		signature = copy.signature;
	return *this;
}

AForm::~AForm(){
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getSig() const {
	return signature;
}

int AForm::getGradeSig() const {
	return gradeS;
}

int AForm::getGradeExe() const {
	return gradeE;
}

void AForm::beSigned(Bureaucrat &b){
	if (b.getGrade() > gradeS) {
		throw (GradeTooLowException());
	}
	signature = true;
}

std::ostream & operator << (std::ostream &out, AForm &f){
	std::cout << "AForm name: " << f.getName() << " is signed: " << f.getSig() << " must have a grade of " << f.getGradeSig() << " to sign it and a grade of " << f.getGradeExe() << " to execute it" << std::endl;
	return out;
}