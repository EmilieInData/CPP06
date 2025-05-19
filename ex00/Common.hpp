/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/05/19 21:15:16 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HPP
# define COMMON_HPP

#define ERROR	"📍"
#define RESET   "\033[0m"
#define BLUE	"\033[38;5;147m"
#define PINK    "\033[38;5;207m"
#define GREEN  	"\033[38;5;194m"
#define PURPLE  "\033[38;5;62m"

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>

void	doChar(char c);
void	doInt(int i);
void	doFloat(std::string value);
void	doDouble(std::string value);

bool	checkInt(std::string value, int len);
bool	intLimits(long l);
bool    checkSpecialValue(std::string value);
bool	checkDecimal(std::string value, int len);
bool	floatLimits(double d);
bool	doubleLimits(std::string value);

void	printChar(double d);
void	printInt(double d);
void	printFloat(double d);

void	errorMessage(int i);

#endif
