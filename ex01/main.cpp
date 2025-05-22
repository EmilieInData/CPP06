/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/22 15:07:02 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Serializer.hpp"

int main(int ac, char **av)
{
	Data 		test1;
	Data* 		test2 = new Data;
	Data* 		tmp = NULL;
	uintptr_t	p;

	(void)av;
	if (ac != 1)
	{
		std::cerr << ERROR << PINK << "Error, no argument required\n" << RESET;
		delete(test2);
		return (1);
	}

	p = Serializer::serialize(&test1);
	tmp = Serializer::deserialize(p);
	std::cout << PURPLE << "\n" << "Test1:" << "\n"
					    << "pointer's adress: " << GREEN << &test1 << "\n"
			  << PURPLE << "unsigned int: " << GREEN << p << "\n"
			  << PURPLE << "pointer's adress deserialized: " << GREEN << tmp
			  << "\n" << "\n" << RESET;
	
	p = Serializer::serialize(test2);
	tmp = Serializer::deserialize(p);
	std::cout << PURPLE << "Test2:" << "\n"
						<< "pointer's adress: " << GREEN << test2 << "\n"
			  << PURPLE << "unsigned int: " << GREEN << p << "\n"
			  << PURPLE << "pointer's adress deserialized: " << GREEN << tmp
			  << "\n" << "\n" << RESET;
	
	delete (test2);
	return (0);
}

//to verify the unsigned value, do this command in bash:
//echo $((pointer's adress))
