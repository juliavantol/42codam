/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sample.class.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:25:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 16:39:16 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

#include <iostream>

// this is a pointer to the current instance
class Sample
{
	public: 
		float const pi;
		int			qd;

		Sample(float const f);
		~Sample(void);
		
		void bar(void) const;
};

#endif