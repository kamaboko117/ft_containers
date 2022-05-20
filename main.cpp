/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:43:58 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/20 15:26:42 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

int	main(){
	int	i = 0;
	
	std::vector<int>	vec;
	ft::vector<int>		ft_vec;
	
	std::vector<int>	vec2(4);
	ft::vector<int>		ft_vec2(4);

	for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
		std::cout << i++ << std::endl;
	i = 0;
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = ft_vec2.begin(); it != ft_vec2.end(); it++)
		std::cout << i++ << std::endl;
}