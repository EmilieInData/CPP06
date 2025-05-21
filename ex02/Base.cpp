/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/21 21:10:08 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Base.hpp"

Base::~Base()
{
	std::cout << PURPLE << ">> Base destructor called" << RESET << std::endl;
}

