/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:12:47 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 15:42:58 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main() {
	int k = 5;
	Bureaucrat office("Yassine" , 4 );
	Form *folder[k];
	try {
		for (int i = 0; i < k; i++) {
			folder[i] = new Form("f" + std::to_string(i), 0,  1 + i, 2 + i);
			office.signForm(folder[i]);
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;		
	}
	for (int i = 0; i < k; i++) {
		delete(folder[i]);
	}
	return 0;
}