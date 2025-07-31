/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:53:13 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/31 10:04:16 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <string>
#include <iostream>
#include "debug.hpp"

Ice::Ice() : AMateria("ice")
{
	if (debug_flag)
		std::cout << "Ice Default Constructor called." << std::endl;
}

Ice::~Ice()
{
	if (debug_flag)
		std::cout << "Ice destructor called." << std::endl;
}

Ice ::Ice(const Ice &other) : AMateria(other)
{
	if (debug_flag)
		std::cout << "Ice Copy Constructor called." << std::endl;
}

const Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria *Ice::clone() const
{
	AMateria *temp = new Ice(*this);
	return temp;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}