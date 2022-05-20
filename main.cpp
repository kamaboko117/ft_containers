/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:43:58 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/20 16:45:42 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>
#include <cstdlib>

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
}