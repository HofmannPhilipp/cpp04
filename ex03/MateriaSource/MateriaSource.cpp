/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:06 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/31 10:37:04 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "debug.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	if (debug_flag)
		std::cout << "MateriaSource Default Constructor called." << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
		slots[i] = NULL;
}
MateriaSource::~MateriaSource()
{
	if (debug_flag)
		std::cout << "MateriaSource Deconstructor called." << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slots[i])
			delete slots[i];
	}
}

MateriaSource ::MateriaSource(const MateriaSource &other)
{
	if (debug_flag)
		std::cout << "MateriaSource Copy Constructor called." << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
		slots[i] = other.slots[i];
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < SLOT_SIZE; i++)
		{
			delete slots[i];
			slots[i] = other.slots[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "[ERROR] Trying to learn a null Materia!" << std::endl;
		return;
	}
	int i;
	for (i = 0; i < SLOT_SIZE; i++)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m->clone();
			std::cout << "[INFO] " << m->getType() << " learned"
					  << " in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "[WARNING] MateriaSource full! Cannot learn new Materia "
			  << m->getType() << "." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slots[i] && type == slots[i]->getType())
			return slots[i]->clone();
	}
	std::cout << "[WARNING] Type:" << type << " does not exist in MateriaSource." << std::endl;
	return NULL;
}