/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:38:43 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/29 19:24:13 by asaboure         ###   ########.fr       */
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

		NAME::stack<int> first;                    // empty stack
		NAME::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque
		NAME::stack<int,NAME::vector<int> > third;  // empty stack using vector
		NAME::stack<int,NAME::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}

	std::cout << std::endl << "****push+pop+top+empty*****" << std::endl;{
		NAME::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
}