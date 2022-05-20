/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:35:49 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/20 18:10:09 by asaboure         ###   ########.fr       */
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
		typedef T * iterator;
		typedef const T * const_iterator;
		
	private:
		T			*array;
		iterator	it_first;
		iterator	it_end;
		iterator	it_last;
		std::size_t	_capacity;
		std::size_t	_size;
	public:
		vector();
		explicit vector(const std::size_t count);
		~vector();

		vector	&operator=(vector const &rhs);
		T		&operator[](std::size_t);
		
		iterator		begin();
		const_iterator	begin() const;
		iterator		end();
		const_iterator	end() const;
		std::size_t		capacity() const;
		std::size_t		size() const;
	};

	//CONSTRUCT
	template<typename T>
	vector<T>::vector() : 	array(new T[10]),
							it_first(array),
							it_end(array),
							it_last(array + 10),
							_capacity(10),
							_size(0){}

	template<typename T>
	vector<T>::vector(const std::size_t count) :	array(new T[count]),
													it_first(array),
													it_end(array + count),
													it_last(array + count),
													_capacity(count),
													_size(count){}

	template<typename T>
	vector<T>::~vector(){
		delete[] array;
	}

	//OPERATORS
	template<typename T>
	vector<T>	&vector<T>::operator=(vector const &rhs){
		if (this == &rhs)
			return (*this);
		this->~vector();
		new(this) vector(rhs.capacity());
		it_first = array;
		it_end = array + rhs.capacity();
		it_last = array + rhs.size();
		for (size_t i = 0; i < size(); i++)
			array[i] = rhs[i];
		return (*this);
	}
	
	template<typename T>
	T	&vector<T>::operator[](std::size_t i){
		return (array[i]);
	}

	//ITERATORS
	template<typename T>
	typename vector<T>::iterator	vector<T>::begin(){
		return (it_first);
	}

	template<typename T>
	typename vector<T>::iterator	vector<T>::end(){
		return (it_end);
	}

	//ETC
	template<typename T>
	std::size_t	vector<T>::capacity() const{
		return (_capacity);
	}

	template<typename T>
	std::size_t	vector<T>::size() const{
		return (_size);
	}
}
#endif