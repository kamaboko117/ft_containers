/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:54:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/21 13:50:52 by asaboure         ###   ########.fr       */
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

bool fncomp (char lhs, char rhs){
	return lhs<rhs;
}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const{
		return lhs<rhs;
	}
};

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

	std::cout << std::endl << "****Construct*****" << std::endl;{
		NAME::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		std::cout << "default constructor with insert" << std::endl;
		for (NAME::map<char,int>::iterator it = first.begin(); it != first.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
		}

		NAME::map<char,int> second (first.begin(),first.end());
		std::cout << "range constructor with first" << std::endl;
		for (NAME::map<char,int>::iterator it = second.begin(); it != second.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
		}
		
		NAME::map<char,int> third (second);
		std::cout << "copy constructor with second" << std::endl;
		for (NAME::map<char,int>::iterator it = third.begin(); it != third.end(); ++it){
			std::cout << it->first << " => " << it->second << '\n';
		}
		
		NAME::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		NAME::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	}

	std::cout << std::endl << "****size()*****" << std::endl;{
		NAME::map<char,int> mymap;

		mymap['a'] = 101;
		mymap['b'] = 202;
		mymap['c'] = 302;

		std::cout << "mymap.size() is " << mymap.size() << '\n';

	}

	std::cout << std::endl << "****operator=*****" << std::endl;{
		NAME::map<char,int> first;
		NAME::map<char,int> second;

		first['x'] = 8;
		first['y'] = 16;
		first['z'] = 32;

		second = first;                // second now contains 3 ints
		first = NAME::map<char,int>();  // and first is now empty

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
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
		for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit){
			std::cout << rit->first << " => " << rit->second << '\n';
		}
	}

	std::cout << std::endl << "****map find*****" << std::endl;{
		NAME::map<char,int> mymap;
		NAME::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	
	std::cout << std::endl << "****map insert*****" << std::endl;{
		NAME::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( NAME::pair<char,int>('a',100) );
		mymap.insert ( NAME::pair<char,int>('z',200) );

		NAME::pair<NAME::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( NAME::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		NAME::map<char,int>::iterator it = mymap.begin();

		mymap.insert (it, NAME::pair<char,int>('b',300));  // max efficiency inserting (no difference in FT)
		mymap.insert (it, NAME::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		NAME::map<char,int> anothermap;
		std::cout << "find: " << mymap.find('c')->first << std::endl;
		anothermap.insert(mymap.begin(),mymap.find('c'));
		// showing contents:
		std::cout << "mymap contains:\n";
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	
		std::cout << "anothermap contains:\n";
		for (it = anothermap.begin(); it != anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
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