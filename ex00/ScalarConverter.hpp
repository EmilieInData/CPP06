/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/05/09 18:49:21 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include "Common.hpp"

class ScalarConverter
{
	public:
		static void	convert(std::string value);
	
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& other);
		~ScalarConverter();
		ScalarConverter& 	operator=(ScalarConverter const& other);

};

#endif
