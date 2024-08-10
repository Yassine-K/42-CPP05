/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:12:47 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 08:44:03 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main() {
	try {
	Bureaucrat office("Yassine " , 1 );
		std::cout << office;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;		
	}
	return 0;
}