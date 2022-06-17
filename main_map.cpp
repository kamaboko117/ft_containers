/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:54:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/17 18:26:44 by asaboure         ###   ########.fr       */
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
#ifndef NAME
# define NAME ft
#endif 

//check bst allocation
int	main(){
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

	std::cout << std::endl << "****BST Search / Insert / delete*****" << std::endl;{
		ft::BstNode<ft::pair<std::string, int> >	*root = NULL;
		ft::pair<std::string, int>		value("value", 42);
		ft::pair<std::string, int>		random("random", 42);
		
		std::cout << "inserting value in BST" << std::endl;
		// root = ft::BstInsert(root, root, value, std::less<std::string>(), std::allocator<ft::BstNode<ft::pair<std::string, int> > >());
		std::cout << std::boolalpha << "bst search value: " << ft::BstSearch(root, value, std::less<std::string>())
			<< std::endl;
		std::cout << std::boolalpha << "bst search random: " << ft::BstSearch(root, random, std::less<std::string>())
			<< std::endl;
		std::cout << "deleting value in BST" << std::endl;
		//not usable outside of map anymore
		//root = ft::BstDelete(root, &value, std::less<std::string>(), std::allocator<ft::BstNode<ft::pair<std::string, int> > >());
		std::cout << std::boolalpha << "bst search value: " << ft::BstSearch(root, value, std::less<std::string>()) << std::endl;;
	}

	std::cout << std::endl << "****map iterators*****" << std::endl;{
		NAME::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		// show content:
		for (NAME::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
		}
	}

	std::cout << std::endl << "****map reverse_iterators*****" << std::endl;{
		NAME::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		NAME::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit){
			std::cout << "loop" << std::endl;
			std::cout << rit->first << " => " << rit->second << '\n';
		}
	}

	std::cout << std::endl << "****map erase*****" << std::endl;{
		NAME::map<char,int> mymap;
		NAME::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
}