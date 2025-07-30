/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:03:06 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/29 16:47:31 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor called." << std::endl;
}
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Deconstructor called." << std::endl;
}

MateriaSource ::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource Copy Constructor called." << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
		this->slots[i] = other.slots[i];
}

const MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < SLOT_SIZE; i++)
		{
			this->slots[i] = other.slots[i];
			// delete other.slots[i];
		}
	}
	return *this;
}