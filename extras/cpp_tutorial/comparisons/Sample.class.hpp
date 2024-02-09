/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sample.class.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:25:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/09 00:29:37 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

#include <iostream>

class Sample
{
public:
	Sample(int v);
	~Sample(void);

	int	getFoo(void) const;
	// taking as a parameter (the address of a sample instance). Making a
	// comparison between the current instance and the passed parameter instance
	int	compare(Sample *other) const ;

private:
	int	_foo;
};

#endif