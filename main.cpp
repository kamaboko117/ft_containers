/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:43:58 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/23 20:28:25 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>
#include <cstdlib>
//vector	empty(0);

void pointer_func(const int* p, std::size_t size)
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
}

int	main(){
	srand(time(0));
	int	i = 0;
	
	std::vector<int>	vec;
	ft::vector<int>		ft_vec;
	std::vector<int>	vec2(4);
	ft::vector<int>		ft_vec2(4);

	for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++){
		vec2[i++] = std::rand();
		std::cout << *it << std::endl;
	}
	i = 0;
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = ft_vec2.begin(); it != ft_vec2.end(); it++){
		ft_vec2[i++] = std::rand();
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	ft::vector<char> letters(4);
	std::cout << "The first character is '" << letters.front() << "'." << std::endl;
	letters[0] = 'o';
	letters[1] = 'm';
	letters[2] = 'f';
	letters[3] = 'g';
    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'." << std::endl;
    }

	std::cout << "****vector.at()*****" << std::endl;{
		ft::vector<int> data(6);
		for (size_t i = 1; i < 7; i++)
			data[i - 1] = i;
	
		// Set element 1
		data.at(1) = 88;
	
		// Read element 2
		std::cout << "Element at index 2 has value " << data.at(2) << std::endl;
	
		std::cout << "data size = " << data.size() << std::endl;
	
		try {
			// Set element 6
			data.at(6) = 666;
		} catch (std::out_of_range const& exc) {
			std::cout << exc.what() << std::endl;
		}
	
		// Print final values
		std::cout << "data:";
		for (ft::vector<int>::iterator it = data.begin(); it != data.end(); it++)
			std::cout << " " << *it;
		std::cout << std::endl;
	}

	std::cout <<  "****vector.data()*****" << std::endl;{
		ft::vector<int> container(4);
		for (size_t i = 0; i < 4; i++)
			container[i] = i + 1;
		pointer_func(container.data(), container.size());
	}

	std::cout <<  "****vector.max_size()*****" << std::endl;{
		ft::vector<char> q;
		std::cout.imbue(std::locale("en_US.UTF-8"));    
		std::cout << "Maximum size of a vector is " << q.max_size() << std::endl;
	}
}