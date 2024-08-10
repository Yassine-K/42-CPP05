/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:21:26 by ykhayri           #+#    #+#             */
/*   Updated: 2024/08/10 12:29:14 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &);
		Intern & operator=(const Intern &);
		~Intern();
		AForm *makeForm(std::string fName, std::string fTarget);
};