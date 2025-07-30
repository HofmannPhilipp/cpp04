/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:56:10 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/30 17:32:39 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

#define SLOT_SIZE 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria *slots[SLOT_SIZE];

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &other);
	const MateriaSource &operator=(const MateriaSource &other);
	void learnMateria(AMateria *) override;
	AMateria *createMateria(std::string const &type) override;
};