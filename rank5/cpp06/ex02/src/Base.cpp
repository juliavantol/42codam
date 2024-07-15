/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/15 16:17:36 by Julia         #+#    #+#                 */
/*   Updated: 2024/07/15 16:55:45 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {};

Base*	generate(void)
{
	std::srand(std::time(0));
	int		result = std::rand() % 3;
	switch(result)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return nullptr;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast< A& >( p );
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (const std::exception& error) {}
	try
	{
		B& b = dynamic_cast< B& >( p );
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch (const std::exception& error) {}
	try
	{
		C& c = dynamic_cast< C& >( p );
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(const std::exception& error) {}
}
