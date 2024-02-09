/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:34:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/09 00:32:19 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"

int	main(void)
{
	// physically different but structurally identical instances
	Sample instance1(42);
	Sample instance2(42);

	if (&instance1 == &instance1)
		std::cout << "instance 1 and instance 1 are physically equal" << std::endl;
	else
		std::cout << "instance 1 and instance 1 are not physically equal" << std::endl;

	if (&instance1 == &instance2)
		std::cout << "instance 1 and instance 2 are physically equal" << std::endl;
	else
		std::cout << "instance 1 and instance 2 are not physically equal" << std::endl;

	if (instance1.compare(&instance1) == 0)
		std::cout << "instance 1 and instance 1 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance 1 are not structurally equal" << std::endl;

	if (instance1.compare(&instance2) == 0)
		std::cout << "instance 1 and instance 2 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance 2 are not structurally equal" << std::endl;

	return (0);
}