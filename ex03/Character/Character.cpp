/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:43:44 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/30 18:10:51 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name("Default")
{
	std::cout << "Character Default Constructor called." << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}
Character::Character(std::string name) : name(name)
{
	std::cout << "Character Default Constructor called." << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

Character ::Character(const Character &other) : Character(other.name)
{
	std::cout << "Character Copy Constructor called." << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = other.inventory[i];
}

const Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			delete inventory[i];
			inventory[i] = other.inventory[i];
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "[ERROR] Trying to equip a null Materia!" << std::endl;
		return;
	}
	int i;
	for (i = 0; i < INVENTORY_SIZE; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "[INFO] " << name << " equipped " << m->getType()
					  << " in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "[WARNING] Inventory full! Cannot equip "
			  << m->getType() << "." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << "[ERROR] Invalid index " << idx
				  << ". Must be between 0 and " << INVENTORY_SIZE - 1 << "!" << std::endl;
		return;
	}
	if (!inventory[idx])
	{
		std::cout << "[WARNING] Slot " << idx << " is already empty."
				  << std::endl;
		return;
	}
	std::cout << "[INFO] Unequipping " << inventory[idx]->getType()
			  << " from slot " << idx << "." << std::endl;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << "[ERROR] Invalid index " << idx
				  << ". Must be between 0 and " << INVENTORY_SIZE - 1 << "!" << std::endl;
		return;
	}
	if (!inventory[idx])
	{
		std::cout << "[WARNING] Slot " << idx << " is empty."
				  << std::endl;
		return;
	}
	inventory[idx]->use(target);
}