/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:44:12 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/31 10:05:11 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>
#include "debug.hpp"

Cure::Cure() : AMateria("cure")
{
	if (debug_flag)
		std::cout << "Cure Default Constructor called." << std::endl;
}

Cure::~Cure()
{
	if (debug_flag)
		std::cout << "Cure destructor called." << std::endl;
}

Cure ::Cure(const Cure &other) : AMateria(other)
{
	if (debug_flag)
		std::cout << "Cure Copy Constructor called." << std::endl;
}

const Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria *Cure::clone() const
{
	AMateria *temp = new Cure(*this);
	return temp;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}