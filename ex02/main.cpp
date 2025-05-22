/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/22 15:13:38 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Base.hpp"

int main(int ac, char **av)
{
	srand(time(NULL));
	
	(void)av;
	if (ac != 1)
	{
		std::cerr << ERROR << PINK << "Error, no argument required\n" << RESET;
		return (1);
	}
	
	A		classA;
	B		classB;
	C		classC;
	Base* 	test1 = generate();
	Base* 	test2 = new A;
	Base* 	test3 = generate();

	identify(classA);
	identify(classB);
	identify(classC);

	identify(test1);
	identify(test2);
	identify(test3);

	delete (test1);
	delete (test2);
	delete (test3);
	return (0);
}
