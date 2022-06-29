/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:38:43 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/29 17:53:28 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <deque>
#include <stack>
#include <vector>

#ifndef NAME
# define NAME ft
#endif 

int	main(){
	std::cout << std::endl << "****construct + size*****" << std::endl;{
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	NAME::vector<int> myvector (2,200);        // vector with 2 elements

	std::cout << "pouet" << std::endl;
	NAME::stack<int> first;                    // empty stack
	std::cout << "dddd" << std::endl;
	NAME::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque
	std::cout << "plouf" << std::endl;
	// NAME::stack<int,NAME::vector<int> > third;  // empty stack using vector
	// NAME::stack<int,NAME::vector<int> > fourth (myvector);

	std::cout << "pouet" << std::endl;
	// std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	// std::cout << "size of third: " << third.size() << '\n';
	// std::cout << "size of fourth: " << fourth.size() << '\n';
	}
}