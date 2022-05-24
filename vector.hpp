/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:35:49 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/24 18:18:14 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <stdexcept>
# include <limits>
# include <memory>

namespace ft
{	
	template<typename vector>
	class iterator
	{
	public:
		typedef	typename vector::value_type T;
	private:
		T	*ptr;
	public:
		iterator(T *ptr)
			: ptr(ptr){}

		iterator	&operator++(){
			ptr++;
			return (*this);
		}
		iterator	operator++(int){
			iterator it = *this;
			++(*this);
			return (it);
		}
		iterator	&operator--(){
			ptr--;
			return (*this);
		}
		iterator	operator--(int){
			iterator it = *this;
			--(*this);
			return (it);
		}
		T			&operator[](std::size_t i){
			return *(ptr[i]);
		}
		T			*operator->(){
			return (ptr);
		}
		T			&operator*(){
			return (*ptr);
		}
		bool		operator==(const iterator &rhs) const{
			return (ptr == rhs.ptr);
		}
		bool		operator!=(const iterator &rhs) const{
			return (ptr != rhs.ptr);
		}
	};

	template<typename T>
	class vector
	{	
	public:
		typedef	T									value_type;
		typedef	std::allocator<T>					allocator_type;
		typedef	std::size_t							size_type;
		typedef	std::ptrdiff_t						difference_type;
		typedef	value_type&							reference;
//		typedef	reference const						const_reference;
		typedef	typename allocator_type::pointer	pointer;
		typedef	pointer const						const_pointer;
		typedef iterator<vector<T> >				iterator;
		typedef iterator const						const_iterator;	
	
		
	private:
		T			*array;
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
		T				&front() const;
		T				&back() const;
		bool			empty() const;
		T				&at(std::size_t pos);
		T				*data();
		T const			*data() const;
		std::size_t		max_size() const;
		void			reserve(std::size_t new_cap);
		void			push_back(const T &value);
		void			clear();
		iterator		insert(iterator pos, const T &value);
		iterator		insert(iterator pos, std::size_t count, const T &value);
		template<class InputIt>
		iterator		insert(iterator pos, InputIt first, InputIt last);
	};

	//CONSTRUCT
	template<typename T>
	vector<T>::vector() : 	array(new T[0]),
							_capacity(0),
							_size(0){}

	template<typename T>
	vector<T>::vector(const std::size_t count) :	array(new T[count]),
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
		for (std::size_t i = 0; i < size(); i++)
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
		return (iterator(array));
	}

	template<typename T>
	typename vector<T>::iterator	vector<T>::end(){
		return (iterator(array + _size));
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

	template<typename T>
	T	&vector<T>::front() const{
		return (array[0]);
	}
	
	template<typename T>
	T	&vector<T>::back() const{
		return (array[_size]);
	}
	
	template<typename T>
	bool	vector<T>::empty() const{
		return (_size == 0 ? true : false);
	}

	template<typename T>
	T	&vector<T>::at(std::size_t pos){
		if (pos >= _size)
			throw std::out_of_range("out of range");
		else
			return (array[pos]);
	}

	template<typename T>
	T	*vector<T>::data(){
		return (array);
	}

	template<typename T>
	T const	*vector<T>::data() const{
		return (array);
	}
	
	template<typename T>
	std::size_t	vector<T>::max_size() const{
		return (std::numeric_limits<difference_type>::max());
	}

	template<typename T>
	void	vector<T>::reserve(std::size_t new_cap){
		T	*tmp;
		
		if (new_cap > max_size())
			throw std::length_error("");	
		else if (new_cap > _capacity){
			tmp = new T[new_cap];
			for (size_t i = 0; i < _size; i++)
				tmp[i] = array[i];
			delete[] array;
			array = tmp;
			_capacity = new_cap;
		}
	}

	template<typename T>
	void	vector<T>::push_back(const T &value){
		if (_capacity == 0)
			reserve(1);
		else if (_size >= _capacity)
			reserve(_capacity * 2);
		array[_size] = value;
		_size++;
	}

	template<typename T>
	void	vector<T>::clear(){
		delete[] array;
		_size = 0;
		array = new T[_capacity];
	}

	template<typename T>
	typename vector<T>::iterator	vector<T>::insert(iterator pos, const T &value){
		*(pos - 1) = value;
		return (*(pos - 1));
	}
}
#endif