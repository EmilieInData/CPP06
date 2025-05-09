/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/09 18:53:43 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
		std::cerr << ERROR << PINK << "Error, this programme required one argument" << "\n";
	ScalarConverter::convert(av[1]);
	return 0;
}
