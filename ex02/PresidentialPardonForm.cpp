/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:35:19 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 12:05:05 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialF", 0, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialF", 0, 25, 5) {
	myTarget = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) {
	myTarget = copy.myTarget;
}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm & copy) {
	if (this != &copy)
		myTarget = copy.myTarget;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSig())
		throw(NotSigned());
	if (this->getGradeExe() < executor.getGrade())
		throw (GradeTooLowException());
	std:: cout << myTarget << " has been pardoned by Zaphod Beeblebrox." << std:: endl;
}