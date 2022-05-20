/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:35:49 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/20 15:25:57 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{	
	template<typename T>
	class vector
	{	
	public:
		vector();
		explicit vector(const std::size_t count);
		~vector();

		typedef T * iterator;
		typedef const T * const_iterator;
		
		iterator		begin();
		const_iterator	begin() const;
		iterator		end();
		const_iterator	end() const;
	
	private:
		T			*array;
		iterator	it_first;
		iterator	it_last;
	
	};
}

//CONSTRUCT
template<typename T>
ft::vector<T>::vector() : array(new T[10]), it_first(array), it_last(array + 10){}

template<typename T>
ft::vector<T>::vector(const std::size_t count) :	array(new T[count]),
													it_first(array),
													it_last(array + count){}

template<typename T>
ft::vector<T>::~vector(){
	delete[] array;
}

//ITERATORS
template<typename T>
typename ft::vector<T>::iterator	ft::vector<T>::begin(){
	return (it_first);
}

template<typename T>
typename ft::vector<T>::iterator	ft::vector<T>::end(){
	return (it_last);
}

#endif