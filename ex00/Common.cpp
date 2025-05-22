/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Common.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:00:58 by esellier          #+#    #+#             */
/*   Updated: 2025/05/22 15:10:11 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "ScalarConverter.hpp"

void	doChar(char c)
{
	int		i;
	float	f;
	double	d;
	
	i = static_cast<int>(c);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	std::cout << PURPLE << "char: ";
	if (c < 32 || c == 127)
		errorMessage(1);
	else
		std::cout << GREEN << "'" << c << "'" << "\n";
	std::cout << PURPLE << "int: " << GREEN << i << "\n"
			  << PURPLE << std::fixed << std::setprecision(1) << "float: "
			  << GREEN << f << "f" << "\n"
			  << PURPLE << std::fixed << std::setprecision(1) << "double: "
			  << GREEN << d << "\n" << RESET;
	return;	
}

void	doInt(int i)
{
	float	f;
	double	d;
	
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	
	printChar(i);
	std::cout << PURPLE << "int: " << GREEN << i << "\n"
			  << PURPLE << std::fixed << std::setprecision(1) << "float: "
			  << GREEN << f << "f" << "\n"
			  << PURPLE << std::fixed << std::setprecision(1) << "double: "
			  << GREEN << d << "\n" << RESET;
	return;	
}

void	doFloat(std::string value)
{
	float	f;
	double	d;
	
	d = atof(value.c_str());
	f = static_cast<float>(d);
	printChar(f);
	printInt(f);
	std::cout << PURPLE << std::fixed << std::setprecision(1) << "float: "
			  << GREEN << f << "f" << "\n"
			  << PURPLE << std::fixed << std::setprecision(1) << "double: "
			  << GREEN << d << "\n" << RESET;
	return;	
}

void	doDouble(std::string value)
{
	double	d;
	
	d = atof(value.c_str());
	printChar(d);
	printInt(d);
	printFloat(d);
	std::cout << PURPLE << std::fixed << std::setprecision(1) << "double: "
			  << GREEN << d << "\n" << RESET;
	return;	
}

bool	checkInt(std::string value, int len)
{
	if(!isdigit(value[0]) && value[0] != '-')
		return false;
	for (int i = 1; i < len; i++)
	{
		if (!std::isdigit(value[i]))
			return false;
	}
	return true;
}

bool	intLimits(long l)
{
	if (l > INT_MAX || l < INT_MIN)
		return false;
	return true;
}

bool	checkSpecialValue(std::string value)
{
	if (value == "nan" || value == "+inf" || value == "-inf"
		|| value == "nanf" || value == "+inff" || value == "-inff"
		|| value == "inf" || value == "inff")
		return true;
	return false;
}

bool	checkDecimal(std::string value, int len)
{
	if (checkSpecialValue(value) == true)
		return true;
	if((!isdigit(value[0]) && value[0] != '-') || (value[0] == '-' && !isdigit(value[1])))
		return false;
	for (int i = 1; i < len; i++)
	{
		if (!std::isdigit(value[i]) && value[i] != '.')
			return false;
		if (value[i] == '.')
		{
			for (int j = i + 1; j < len - 1; j++)
			{
				if (!std::isdigit(value[j]))
					return false;
			}
			if (!std::isdigit(value[len - 1]) && value[len - 1] != 'f') 
				return false;
			return true;
		}
	}
	return false;
}

bool	floatLimits(double d)
{
	if (d > FLT_MAX || d < -FLT_MAX)
		return false;
	return true;
}

bool	doubleLimits(std::string value)
{
	double	d;
	try
	{
		d = atof(value.c_str());
	}
	catch(const std::out_of_range& e)
	{
		return false;
	}
	return true;
}

void	printChar(double d)
{
	char 	c;

	std::cout << PURPLE << "char: ";
	if (d > 31 && d < 127)
	{
		c = static_cast<char>(d);
		std::cout << GREEN << "'" << c << "'" << "\n";
	}
	else if ((d >= 0 && d < 32) || d == 127)
		errorMessage(1);
	else if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
		errorMessage(2);
	return ;
}

void	printInt(double d)
{
	int	i;
	
	std::cout << PURPLE << "int: ";
	if (intLimits(d) == true)
	{
		i = static_cast<int>(d);
		std::cout << GREEN << i << "\n";
	}
	else if (std::isnan(d) || std::isinf(d))
		errorMessage(2);
	else
		errorMessage(3);
	return;
}

void	printFloat(double d)
{
	float	f;
	
	std::cout << PURPLE << "float: ";
	if (floatLimits(d) == true)
	{
		f = static_cast<float>(d);
		std::cout << GREEN << std::fixed << std::setprecision(1) << f << "f" << "\n";
	}
	else
		errorMessage(3);
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
		case 4:
			std::cerr << PINK << ERROR 
					  << " Invalid value, overflow"
					  << RESET << std::endl;
			break;
		default:
			std::cerr << PINK << ERROR 
					  << " Invalid value, only char; int; float or double values are allowed"
					  << RESET << std::endl;
	}
	return ;
}
