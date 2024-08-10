/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:12:47 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 12:17:47 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
	try {
		int k = 5;
		Bureaucrat user("Yassine" , 4 );
		AForm *folder[k];
		for (int i = 0; i < k; i++) {
			std::cout << i << " " << std::endl;
			folder[i] = new PresidentialPardonForm("yassine");
			if (i%2)
				user.signForm(folder[i]);
			user.executeForm(*folder[i]);
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;		
	}
	return 0;
}