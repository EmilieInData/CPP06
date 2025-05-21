/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/21 19:48:50 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << PURPLE << ">> ScalarConverter default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& other)
{
	(void) other;
	std::cout << PURPLE << ">> ScalarConverter copy constructor called" << RESET << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << PURPLE << ">> ScalarConverter destructor called" << RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other)
{
	if (this == &other)
		std::cout << ERROR << PINK
				  << "pay attention, you're trying to assign a ScalarConverter class to itself"
				  << RESET << std::endl;
	return (*this);
}

bool	ScalarConverter::convert(std::string value)
{
	int	len;
	
	len = value.length();
	//char
	if (len == 1 && (value[0] < '0' || value[0] > '9'))
		doChar(value[0]);
	//int
	else if(checkInt(value, len) == true)
	{
		if(intLimits(atol(value.c_str())) == false)
		{
			errorMessage(4);
			return false;
		}
		doInt(atoi(value.c_str()));
	}
	//float & double
	else if (checkDecimal(value, len))
	{
		if (value[len - 1] == 'f')
		{
			if(floatLimits(atol(value.c_str())) == false)
			{
				errorMessage(4);
				return false;
			}
			doFloat(value);
		}
		else
		{
			if(doubleLimits(value) == false)
			{
				errorMessage(4);
				return false;
			}
			doDouble(value);
		}
	}
	else
	{
		errorMessage(42);
		return false;
	}
	return true ;
}
