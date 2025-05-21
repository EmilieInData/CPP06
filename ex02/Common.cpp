/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Common.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/21 21:32:37 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Base.hpp"

Base*   generate(void)
{
	int		i;
	Base*	tmp = NULL;

	i = rand() % 3;
	switch (i)
	{
	case 0:
		tmp = new A;
		break;
	case 1:
		tmp = new B;
		break;
	case 2:
		tmp = new C;
		break;
	default:
		std::cerr << PINK << ERROR << " Error with rand function" << RESET "\n";
	}
	return (tmp);
}

void    identify(Base* p)
{
	std::cout << PURPLE "Type of the pointed objet: ";
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "C\n";
	else
		std::cout << GREEN << "Unknow\n";
	return;
}

void    identify(Base& p)
{
	std::cout << PURPLE "Type of the referenced objet: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << GREEN << "A\n";
		return;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << GREEN << "B\n";
		return;
	}
	catch (...){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << GREEN << "C\n";
		return;
	}
	catch (...){}
	std::cout << GREEN << "Unknow\n";
	return ;
}
