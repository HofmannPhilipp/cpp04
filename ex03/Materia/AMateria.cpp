/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:25:03 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/30 12:53:51 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("AMateria")
{
	std::cout << "AMateria Default Constructor called." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria Constructor called." << std::endl;
}

AMateria ::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "AMateria Copy Constructor called." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
}