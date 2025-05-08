/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/08 19:52:59 by esellier         ###   ########.fr       */
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
				  << "pay attention, you're trying to assign an Bureaucrat class to itself"
				  << RESET << std::endl;
	return (*this);
}

void	ScalarConverter::convert(std::string value)
{
	int	len;
	
	len = value.length();
	//char
	if (len == 1)
		doChar(value[0]);
	//int
	else if(digits(value, len) == true)
	{
		if(checkLimits(std::stol(value)) == false)
			return(errorMessage(42));
		doInt(std::stoi(value), len);
	}
		
	//checkstring puis float ou double
	//float
	else if(value[len - 1] == 'f' || value[len - 1] == 'F')
		doFloat(value); //penser float min max 
	//double
	else if()
	
	else
		errorMessage(42);
	return ;
}

void	doInt(int i, int len)
{
	char 	c;
	float	f;
	double	d;
	
	
	std::cout << PURPLE << "char: " << GREEN << c << "\n"
			  << PURPLE << "int: " << GREEN << i << "\n"
			  << PURPLE << "float: " << GREEN << f << "\n"
			  << PURPLE << "double: " << GREEN << d << "\n";
	return;	
}

void	checkString(std::string value)
{
	
}

bool	digits(std::string value, int len)
{
	//checker les signes
	for (int i = 0; i < len; i++)
	{
		if (!std::isdigit(value[i]))
			return false;
	}
	return true;
}
bool	checkLimits(long l)
{
	if (l > INT_MAX || l < INT_MIN)
		return false;
	return true;
}

void	doChar(char c)
{
	int		i;
	float	f;
	double	d;
	
	i = static_cast<int>(c);
	if (i < 32)
		return (errorMessage(0));
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	std::cout << PURPLE << "char: " << GREEN << c << "\n"
			  << PURPLE << "int: " << GREEN << i << "\n"
			  << PURPLE << "float: " << GREEN << f << "\n"
			  << PURPLE << "double: " << GREEN << d << "\n";
	return;	
}

void	errorMessage(int i)
{
	switch(i)
	{
		case 0:
			std::cerr << PINK << ERROR 
					  << " Invalid value, non-displayable values are not allowed"
					  << RESET << std::endl;
			break;		
		case 1:
			std::cout << BLUE << "Not displayable" << RESET << std::endl;
			break;
		case 2:
			std::cout << BLUE << "Not convertible" << RESET << std::endl;
			break;
		case 3:
			std::cout << BLUE << "Value overflow" << RESET << std::endl;
			break;
		default:
			std::cerr << PINK << ERROR 
					  << " Invalid value, only char; int; float or double values are allowed"
					  << RESET << std::endl;
	}
	return ;
}
