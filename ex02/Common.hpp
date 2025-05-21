/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/05/21 20:09:05 by esellier         ###   ########.fr       */
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
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif
