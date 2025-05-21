/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:57:26 by esellier          #+#    #+#             */
/*   Updated: 2025/05/21 21:10:16 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include "Common.hpp"

class Base
{
	public:
		virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

#endif
