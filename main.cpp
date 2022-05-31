/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:43:58 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/31 20:22:51 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#ifndef VECTOR
# define VECTOR ft::vector
#endif
//vector	empty(0);
//check iterator invalidation
//remove iostream from hpp
template <typename T>
void	printSize(VECTOR<T> const &vct, bool print_content = true)
{
	const std::size_t size = vct.size();
	const std::size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename VECTOR<T>::const_iterator it = vct.begin();
		typename VECTOR<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; it++)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	checkErase(VECTOR<std::string> const &vct,
					VECTOR<std::string>::iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

void pointer_func(const int* p, std::size_t size)
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
}

void print(int id, VECTOR<int>& container){
	std::cout << id << ". ";
	for (VECTOR<int>::iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << ' ';
	}
	std::cout << '\n';
}

template<typename T>
void printpb(T &xs)
{
    std::cout << "[ ";
    for(typename T::iterator it = xs.begin(); it != xs.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << "]\n";
}

int	main(){
	srand(time(0));
std::cout << "plouf" << std::endl;
	VECTOR<std::string> vct(10);
	
std::cout << "plouf" << std::endl;
	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
std::cout << "plouf" << std::endl;
	printSize(vct);
std::cout << "plouf" << std::endl;
	checkErase(vct, vct.erase(vct.begin() + 2));

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back("Hello");
	vct.push_back("Hi there");
	printSize(vct);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	printSize(vct);
	checkErase(vct, vct.erase(vct.begin(), vct.end()));


	// std::cout << std::endl << "****random tests*****" << std::endl;{
	// 	int	i = 0;
		
	// 	VECTOR<int>		vec;
	// 	VECTOR<int>		src(4);
	// 	VECTOR<int>		vec2(src);

	// 	for (VECTOR<int>::iterator it = vec2.begin(); it != vec2.end(); it++){
	// 		vec2[i++] = std::rand();
	// 		std::cout << *it << std::endl;
	// 	}
	// 	i = 0;
	// 	std::cout << std::endl;
	// 	for (VECTOR<int>::iterator it = vec2.begin(); it != vec2.end(); it++){
	// 		vec2[i++] = std::rand();
	// 		std::cout << *it << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// 	VECTOR<char> letters(4);
	// 	std::cout << "The first character is '" << letters.front() << "'." << std::endl;
	// 	letters[0] = 'o';
	// 	letters[1] = 'm';
	// 	letters[2] = 'f';
	// 	letters[3] = 'g';
	// 	if (!letters.empty()) {
	// 		std::cout << "The first character is '" << letters.front() << "'." << std::endl;
	// 	}
	// }
	
	// std::cout << std::endl << "****vector.at()*****" << std::endl;{
	// 	VECTOR<int> data(6);
	// 	for (size_t i = 1; i < 7; i++)
	// 		data[i - 1] = i;
	
	// 	// Set element 1
	// 	data.at(1) = 88;
	
	// 	// Read element 2
	// 	std::cout << "Element at index 2 has value " << data.at(2) << std::endl;
	
	// 	std::cout << "data size = " << data.size() << std::endl;
	
	// 	try {
	// 		// Set element 6
	// 		data.at(6) = 666;
	// 	} catch (std::out_of_range const& exc) {
	// 		std::cout << exc.what() << std::endl;
	// 	}
	
	// 	// Print final values
	// 	std::cout << "data:";
	// 	for (VECTOR<int>::iterator it = data.begin(); it != data.end(); it++)
	// 		std::cout << " " << *it;
	// 	std::cout << std::endl;
	// }

	// // std::cout << std::endl <<  "****vector.data()*****" << std::endl;{
	// // 	VECTOR<int> container(4);
	// // 	for (size_t i = 0; i < 4; i++)
	// // 		container[i] = i + 1;
	// // 	pointer_func(container.data(), container.size());
	// // }

	// std::cout << std::endl <<  "****vector.max_size()*****" << std::endl;{
	// 	VECTOR<char> q;
	// 	std::cout.imbue(std::locale("en_US.UTF-8"));    
	// 	std::cout << "Maximum size of a vector is " << q.max_size() << std::endl;
	// }

	// std::cout << std::endl << "****vector.reserve()*****" << std::endl;{
	// 	int max_elements = 32;
 
	// 	std::cout << "using reserve: \n";
	// 	{
	// 		VECTOR<int> v1;
	// 		v1.reserve( max_elements ); // reserves at least max_elements * sizeof(int) bytes
	// 		for(int n = 0; n < max_elements + 1; ++n){
	// 			if(v1.size() == v1.capacity()) {
	// 				std::cout << "size() == capacity() == " << v1.size() << '\n';
	// 			}
	// 			v1.push_back(n);
	// 		}
	// 	}
	
	// 	std::cout << "not using reserve: \n";
	// 	{
	// 		VECTOR<int> v1;
	// 		for(int n = 0; n < max_elements; ++n) {
	// 			if(v1.size() == v1.capacity()) {
	// 				std::cout << "size() == capacity() == " << v1.size() << '\n';
	// 			}
	// 			v1.push_back(n);
	// 		}
	// 	}
	// }

	// std::cout << std::endl << "****vector.clear()*****" << std::endl;{
	// VECTOR<int> container(3);
	// container[0] = 1;
	// container[1] = 2;
	// container[2] = 3;
 
    // std::cout << "Before clear:";
	// for (VECTOR<int>::iterator it = container.begin(); it != container.end(); it++)
	// 	std::cout << " " << *it;
	
    // std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
 
    // std::cout << "Clear\n";
    // container.clear();
 
    // std::cout << "After clear:";
    // for (VECTOR<int>::iterator it = container.begin(); it != container.end(); it++)
	// 	std::cout << " " << *it;
    // std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
	// }

	// std::cout << std::endl << "****vector.insert()*****" << std::endl;{
	// 	VECTOR<int> c1(3, 100);
	// 	print(1, c1);
	
	// 	VECTOR<int>::iterator it = c1.begin();
	// 	it = c1.insert(it, 200);
	// 	print(2, c1);

	// 	c1.insert(it, 2, 300);
	// 	print(3, c1);
	
	// 	// `it` no longer valid, get a new one:
	// 	it = c1.begin();
	
	// 	VECTOR<int> c2(2, 400);
	// 	c1.insert(it + 2, c2.begin(), c2.end());
	// 	print(4, c1);
	
	// 	int arr[] = { 501,502,503 };
	// 	c1.insert(c1.begin(), arr, arr + 3);
	// 	print(5, c1);
	
	// 	int arr2[] = { 601,602,603 };
	// 	c1.insert(c1.end(), arr2, arr2 + 3);
	// 	print(6, c1);
	// }
	
	// std::cout << std::endl << "****vector.assign()*****" << std::endl;{
	// 	VECTOR<int> first;
	// 	VECTOR<int> second;
	// 	VECTOR<int> third;

	// 	first.assign (7,100);             // 7 ints with a value of 100

	// 	VECTOR<int>::iterator it;
	// 	it=first.begin()+1;

	// 	second.assign (it,first.end()-1); // the 5 central values of first

	// 	int myints[] = {1776,7,4};
	// 	third.assign (myints,myints+3);   // assigning from array.

	// 	std::cout << "Size of first: " << int (first.size()) << '\n';
	// 	std::cout << "Size of second: " << int (second.size()) << '\n';
	// 	std::cout << "Size of third: " << int (third.size()) << '\n';
	// }
	
	// std::cout << std::endl << "****vector.pop_back()*****" << std::endl;{
	// 	VECTOR<int> numbers;
 
	// 	printpb(numbers); 
	
	// 	numbers.push_back(5);
	// 	numbers.push_back(3);
	// 	numbers.push_back(4);
	
	// 	printpb(numbers); 
	
	// 	numbers.pop_back();
	
	// 	printpb(numbers);
	// }

	// std::cout << std::endl << "****vector.erase()*****" << std::endl;{
	// 	VECTOR<int> myvector;

	// 	// set some values (from 1 to 10)
	// 	for (int i=1; i<=10; i++) myvector.push_back(i);

	// 	// erase the 6th element
	// 	myvector.erase (myvector.begin()+5);

	// 	// erase the first 3 elements:
	// 	myvector.erase (myvector.begin(),myvector.begin()+3);

	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector.size(); ++i)
	// 		std::cout << ", " << myvector[i];
	// 	std::cout << '\n';
	// }
	
	std::cout << "DONE" << std::endl;
}