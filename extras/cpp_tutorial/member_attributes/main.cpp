/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:34:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 15:44:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"

int main(void)
{
	// this is a stack variable
	Sample instance;

	instance.foo = 42;
	std::cout << "instance.foo: " << instance.foo << std::endl;

	instance.mem();
	return (0);
}
