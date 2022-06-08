/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:54:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/08 15:37:07 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <functional>
#include <string>
#include "map.hpp"

#ifndef PAIR
# define PAIR ft::pair
#endif 

int	main(){
	ft::map<std::string, int>	map;

	std::cout << std::endl << "****pair*****" << std::endl;{
		std::pair <std::string,double> product1;                     // default constructor
		std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
		std::pair <std::string,double> product3 (product2);          // copy constructor

		product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

		product2.first = "shoes";                  // the type of first is string
		product2.second = 39.90;                   // the type of second is double

		std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	}

	std::cout << std::endl << "****BST Search / Insert*****" << std::endl;{
		ft::BstNode<std::string, int>	*root = NULL;
		ft::pair<std::string, int>		value("value", 42);
		ft::pair<std::string, int>		random("random", 42);
		
		std::cout << "inserting value in BST" << std::endl;
		root = ft::BstInsert<std::string, int>(root, value, std::less<std::string>(), std::allocator<ft::BstNode<std::string, int> >());
		std::cout << std::boolalpha << "bst search value: " << ft::BstSearch(root, value, std::less<std::string>())
			<< std::endl;
		std::cout << std::boolalpha << "bst search random: " << ft::BstSearch(root, random, std::less<std::string>())
			<< std::endl;
	}
}