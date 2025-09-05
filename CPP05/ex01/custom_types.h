/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voparkan <voparkan@student.42prague.cz>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:45:08 by voparkan          #+#    #+#             */
/*   Updated: 2025/09/05 15:26:19 by voparkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Vojtěch Parkán on 30.08.2025.
//

#ifndef CPP42_CUSTOM_TYPES_H
#define CPP42_CUSTOM_TYPES_H

#include <iostream>

class GradeTooHighExeption : virtual public std::exception {
	public:
		GradeTooHighExeption();
		const char * what() const throw();
};

class GradeTooLowExeption : virtual public std::exception {
	public:
		GradeTooLowExeption();
		const char * what() const throw();
};

#endif //CPP42_CUSTOM_TYPES_H
