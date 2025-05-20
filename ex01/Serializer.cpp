/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/20 15:21:38 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << PURPLE << ">> Serializer default constructor called" << RESET << std::endl;
}

Serializer::Serializer(Serializer const& other)
{
	(void) other;
	std::cout << PURPLE << ">> Serializer copy constructor called" << RESET << std::endl;
}

Serializer::~Serializer()
{
	std::cout << PURPLE << ">> Serializer destructor called" << RESET << std::endl;
}

Serializer& Serializer::operator=(Serializer const& other)
{
	if (this == &other)
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign a Serializer class to itself"
				  << RESET << std::endl;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
