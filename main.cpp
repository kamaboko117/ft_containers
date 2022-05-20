/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:43:58 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/20 19:59:14 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>
#include <cstdlib>
//vector	empty(0);

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
	std::cout << "The first character is '" << letters.front() << "'.\n";
	letters[0] = 'o';
	letters[1] = 'm';
	letters[2] = 'f';
	letters[3] = 'g';
    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    }

	std::vector<int> data(6);
	for (size_t i = 1; i < 7; i++)
		data[i - 1] = i;
 
    // Set element 1
    data.at(1) = 88;
 
    // Read element 2
    std::cout << "Element at index 2 has value " << data.at(2) << '\n';
 
    std::cout << "data size = " << data.size() << '\n';
 
    try {
        // Set element 6
        data.at(6) = 666;
    } catch (std::out_of_range const& exc) {
        std::cout << exc.what() << '\n';
    }
 
    // Print final values
    std::cout << "data:";
    for (std::vector<int>::iterator it; it != data.end(); it++)
        std::cout << " " << *it;
    std::cout << '\n';
}