/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:23:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/31 16:42:53 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "debug.hpp"
#include <iostream>

void moreTests()
{
	std::cout << "=== Test 1: Full Inventory ===\n";
	Character me("Player");
	for (int i = 0; i < 4; ++i)
		me.equip(new Ice());
	// AMateria *ice = new Ice();
	// me.equip(ice); // Character "me" inventory full delete ice
	// delete ice;

	std::cout << "\n=== Test 2: Invalid Unequip Index ===\n";
	me.unequip(-1);
	me.unequip(4); // outside the inventory

	std::cout << "\n=== Test 3: Deep Copy ===\n";
	Character copy = me;
	copy.use(0, me); // should be independent from "me"

	std::cout << "\n=== Test 4: MateriaSource with Unknown Type ===\n";
	MateriaSource src;
	// src.learnMateria(new Ice()); // memory leak
	AMateria *ice = new Ice();
	src.learnMateria(ice);
	delete ice;
	AMateria *m = src.createMateria("cure"); // cure not learned yet
	if (!m)
		std::cout << "[INFO] Materia not found!\n";

	std::cout << "\n=== Test 5: Unequip Should NOT Delete Materia ===\n";
	AMateria *saved = new Ice();
	Character me2("Player2");
	me2.equip(saved);
	me2.unequip(0);
	delete saved;
}

int main(int argc, char **argv)
{
	if (argc > 1 && std::string(argv[1]) == "--debug")
		debug_flag = true;
	IMateriaSource *src = new MateriaSource();
	AMateria *ice = new Ice();
	src->learnMateria(ice);
	delete ice;
	AMateria *cure = new Cure();
	src->learnMateria(cure);
	delete cure;
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	moreTests();
	delete bob;
	delete me;
	delete src;
	return 0;
}