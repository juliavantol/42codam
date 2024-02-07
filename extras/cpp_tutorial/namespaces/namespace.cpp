/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   namespace.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 14:11:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/07 14:11:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <stdio.h>

int	gl_var = 1;
int	f(void){return 2;}

namespace	Foo
{
	int	gl_var = 3;
	int	f(void){return 4;}
}

namespace	Bar
{
	int	gl_var = 5;
	int	f(void){return 6;}
}

namespace Muf = Bar;

// :: scope resolution operator
int main(void)
{
	printf("var: %d\n", gl_var);
	printf("f() %d\n", f());
	printf("\n");
	// same as
	printf("::var: %d\n", ::gl_var);
	printf("::f() %d\n", ::f());
	printf("\n");

	// :: makes the call in the foo namespace
	// -> from the foo function call this variable
	printf("Foo::gl_var: %d\n", Foo::gl_var);
	printf("Foo::f() %d\n", Foo::f());
	printf("\n");

	// :: makes the call in the bar namespace
	printf("Bar::gl_var: %d\n", Bar::gl_var);
	printf("Bar::f() %d\n", Bar::f());
	printf("\n");

	// :: makes the call in the muf namespace
	printf("Muf::gl_var: %d\n", Muf::gl_var);
	printf("Muf::f() %d\n", Muf::f());
	printf("\n");
}