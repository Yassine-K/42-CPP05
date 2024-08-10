/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:30:28 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 12:04:05 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShruberryF", 0, 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShruberryF", 0, 145, 137) {
	myTarget = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy) {
	myTarget = copy.myTarget;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm & copy) {
	if (this != &copy)
		myTarget = copy.myTarget;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSig())
		throw(NotSigned());
	if (this->getGradeExe() < executor.getGrade())
		throw(GradeTooLowException());
	std::ofstream myTree(myTarget + "_shrubbery");
	myTree << "          .     .  .      +     .      .          .\n     .       .      .     #       .           .\n        .      .         ###            .      .      .\n      .      .   \"#:. .:##\"##:. .:#\"  .      .\n          .      . \"####\"###\"####\"  .\n       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n  .             \"#########\"#########\"        .        .\n        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n                .\"##\"#####\"#####\"##\"           .      .\n    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n      .     \"#######\"##\"#####\"##\"#######\"      .     .\n    .    .     \"#####\"\"#######\"\"#####\"    .      .\n            .     \"      000      \"    .     .\n       .         .   .   000     .        .       .\n.. .. ..................O000O........................ ......" << std::endl;
}