/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:28:31 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 13:08:28 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

Intern::Intern() {
}

Intern::Intern(const Intern &) {
}

Intern & Intern::operator=(const Intern &) {
	return *this;
}

Intern::~Intern() {
}

AForm *Intern::makeForm(std::string fName, std::string fTarget) {
	try {
		std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
		std::cout << "Intern creates " << fName << std::endl;
		int i = -1;
		while (++i < 3)
			if (types[i] == fName)
				break;
		switch (i) {
			case 0:
				return new ShrubberyCreationForm(fTarget);
				break;
			case 1:
				return new RobotomyRequestForm(fTarget);
				break;
			case 2:
				return new PresidentialPardonForm(fTarget);
				break;
			default:
				throw(std::invalid_argument("No such form"));
		}
	}
	catch (std::exception & e) {
		std::cout << fName << ": No such form!" << std::endl;
		return NULL;
	}
}
