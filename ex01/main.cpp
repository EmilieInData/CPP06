/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:44:12 by esellier          #+#    #+#             */
/*   Updated: 2025/05/20 15:50:23 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Serializer.hpp"

int main()
{
	Data 		test1;
	Data* 		test2 = new Data;
	Data* 		tmp = NULL;
	uintptr_t	p;

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
