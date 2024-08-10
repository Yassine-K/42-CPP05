/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:19:40 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 12:17:30 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotoF", 0, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotoF", 0, 72, 45) {
	myTarget = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) {
	myTarget = copy.myTarget;
}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm & copy) {
	if (this != &copy)
		myTarget = copy.myTarget;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	static int ran = 0;
	if (!this->getSig())
		throw(NotSigned());
	if (this->getGradeExe() < executor.getGrade())
		throw (GradeTooLowException());
	std:: cout << "Hfar Hfar..." << std:: endl;
	std:: cout << "Hfar Hfar......" << std:: endl;
	std:: cout << "Hfar Hfar..." << std:: endl;
	std:: cout << "Hfar Hfar.........." << std:: endl;
	if (ran++)
		std:: cout << myTarget << "has been robotomized successfull!" << std:: endl;
	else
		std:: cout << myTarget + " Robotomy failed!" << std::endl;;
}