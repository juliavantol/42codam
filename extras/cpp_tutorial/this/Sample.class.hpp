/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sample.class.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:25:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 15:54:20 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

#include <iostream>

// this is a pointer to the current instance
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