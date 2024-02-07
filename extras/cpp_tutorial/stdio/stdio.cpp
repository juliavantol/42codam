/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stdio.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:11:45 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 14:11:47 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// << >> redirects the flow to or from a stream (like std::cout or std::cin)
int main(void)
{
	char buffer[512];

	// redirect to standard output
	std::cout << "Hello world!" << std::endl;
	std::cout << "Enter a word: ";

	// standard input, >> because you put it into the buffer
	std::cin >> buffer;

	std::cout << "You entered: [" << buffer << "]" << std::endl;
}
