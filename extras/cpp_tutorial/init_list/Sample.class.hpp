/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sample.class.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:25:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 16:19:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

#include <iostream>

// this is a pointer to the current instance
class Sample
{
	public: 
		char	a1;
		int		a2;
		float	a3;

		Sample(char p1, int p2, float p3);
		~Sample(void);
};

#endif