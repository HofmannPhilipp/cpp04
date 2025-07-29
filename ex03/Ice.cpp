/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:53:13 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/29 15:39:16 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <string>
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default Constructor called." << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called." << std::endl;
}

Ice ::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice Copy Constructor called." << std::endl;
}

const Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria *AMateria::clone() const
{
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}