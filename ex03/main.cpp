/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:12:47 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 13:13:20 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>


int main() {
	try {
		int k = 5;
		Intern user;
		AForm *folder[k];
		Bureaucrat br("Yassine" , 4 );
		for (int i = 0; i < k; i++) {
			if (!i)
				folder[i] = user.makeForm("shrubbery creation", "Test" + std::to_string(i));
			else if (i%2)
				folder[i] = user.makeForm("robotomy request", "Test" + std::to_string(i));
			else if (!(i%2))
				folder[i] = user.makeForm("presidential pardon", "Test" + std::to_string(i));
			if (i%2)
				br.signForm(folder[i]);
			br.executeForm(*folder[i]);
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;		
	}
	return 0;
}