/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:20:05 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/08 19:36:21 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
	public:
		typedef T1	first_type;
		typedef T2	second_type;
		
		pair();
		template<class U, class V>
		pair(const pair<U, V> &src);
		pair(const first_type &a, const second_type &b);

		pair&	operator=(const pair &src);
		
		first_type	first;
		second_type	second;	
	};

	template<class T1, class T2>
	pair<T1, T2>::pair()
		: first(T1()),
		second(T2()){}

	template<class T1, class T2>
	template<class U, class V>
	pair<T1, T2>::pair(const pair<U, V> &src)
		: first(src.first),
		second(src.second){}
	
	template<class T1, class T2>
	pair<T1, T2>::pair(const first_type &a, const second_type &b)
		: first(a),
		second(b){}
	
	template<class T1, class T2>
	pair<T1, T2>	&pair<T1, T2>::operator=(const pair &rhs){
		// if (*this == rhs)
		// 	return (*this);
		first = rhs.first;
		second = rhs.second;
		return (*this);
	}

	template<class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y){
		return (pair<T1, T2>(x, y));
	}
}

#endif