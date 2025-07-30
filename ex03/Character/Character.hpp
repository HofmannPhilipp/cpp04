/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:43:34 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/30 17:11:19 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[INVENTORY_SIZE];

public:
	Character();
	Character(std::string name);
	~Character();
	Character(const Character &other);
	const Character &operator=(const Character &other);
	std::string const &getName() const override;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};