/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sample.class.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:25:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 15:38:39 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

#include <iostream>

// a foo variable will be set up for every class and would be different for each of them
// in c you couldn't add functions in a struct, only with pointers
class Sample
{
	public: 
		int	foo;
		
		// constructor
		Sample(void);
		// deconstructor
		~Sample(void);

		// a member function
		void mem(void);
};

#endif