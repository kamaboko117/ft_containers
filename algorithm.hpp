/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:23:06 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/01 16:40:11 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{
	//https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
	template<class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
		while (first1 != last1)
		{
    		if (first2 == last2 || *first2 < *first1)
				return false;
    		else if (*first1 < *first2)
				return true;
    		++first1;
			++first2;
  		}
  	return (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp){
		while (first1 != last1)
		{
    		if (first2 == last2 || comp(*first2, *first1))
				return false;
    		else if (comp(*first1, *first2))
				return true;
    		++first1;
			++first2;
  		}
  	return (first2 != last2);
	}
	
}

#endif