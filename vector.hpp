/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:35:49 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/31 19:19:15 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <stdexcept>
# include <limits>
# include <memory>
# include "iterator.hpp"
# include "type_traits.hpp"
# include "utils.hpp"

#include <iostream>
namespace ft
{	
	template<typename T>
	class iterator
	{
	public:
		typedef T 				value_type;
		typedef std::ptrdiff_t	difference_type;
	private:
		T	*ptr;
	public:
		iterator(){}
		iterator(T *ptr)
			: ptr(ptr){}
		~iterator(){}
		
		iterator	&operator++(){
			this->ptr++;
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
		T			&operator*() const{
			return (*ptr);
		}
		bool		operator==(const iterator &rhs) const{
			return (ptr == rhs.ptr);
		}
		bool		operator!=(const iterator &rhs) const{
			return (ptr != rhs.ptr);
		}
		iterator	operator+(std::size_t i) const{
			return (iterator(ptr + i));
		}
		iterator	operator-(std::size_t i) const{
			return (iterator(ptr - i));
		}

		T	*base() const{
			return (ptr);
		}
	};

	template <typename T>
    typename iterator<T>::difference_type	operator+(const iterator<T> lhs, const iterator<T> rhs){
        return (lhs.base() + rhs.base());
    }
	template <typename T>
    typename iterator<T>::difference_type	operator-(const iterator<T> lhs, const iterator<T> rhs){
        return (lhs.base() - rhs.base());
    }
	template<typename T_L, typename T_R>
    typename iterator<T_L>::difference_type	operator-(const iterator<T_L> lhs, const iterator<T_R> rhs){
        return (lhs.base() - rhs.base());
    }
	
	template<typename T, class Alloc = std::allocator<T> >
	class vector
	{	
	public:
		typedef	T									value_type;
		typedef	Alloc								allocator_type;
		typedef	value_type&							reference;
		typedef	const value_type&					const_reference;
		typedef	typename allocator_type::pointer	pointer;
		typedef	pointer const						const_pointer;
		typedef iterator<T>							iterator;
		typedef ft::iterator<T const>				const_iterator;
		typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef reverse_iterator<iterator>			reverse_iterator;
		typedef	std::size_t							size_type;
		typedef	std::ptrdiff_t						difference_type;
		
	private:
		allocator_type	_alloc;
		std::size_t		_capacity;
		std::size_t		_size;
		T				*array;
	public:
		explicit vector(const allocator_type &alloc = allocator_type());
		explicit vector(const std::size_t count, const T &value = T(), const allocator_type &alloc = allocator_type());
		template<class InputIt>
		vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type());
		vector(const vector &rhs);
		~vector();

		vector	&operator=(vector const &rhs);
		T		&operator[](std::size_t);
		const T	&operator[](std::size_t) const;
		
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		reverse_iterator		rend() const;
		
		std::size_t				size() const;
		std::size_t				max_size() const;
		void					resize(std::size_t n, T value = T());
		std::size_t				capacity() const;
		bool					empty() const;
		void					reserve(std::size_t new_cap);
		
		T						&at(std::size_t pos);
		T const					&at(std::size_t post) const;
		T						&front();
		T const					&front() const;
		T						&back();
		T const					&back() const;
		// T						*data();
		// T const					*data() const;
		
		void					assign(std::size_t count, const T &value);
		template<class InputIt>
		void					assign(InputIt first, InputIt last, 
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type());
		void					push_back(const T &value);
		void					pop_back();
		iterator				insert(iterator pos, const T &value);
		iterator				insert(iterator pos, std::size_t count, const T &value);
		template<class InputIt>
		iterator				insert(iterator pos, InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type());
		iterator				erase(iterator pos);
		iterator				erase(iterator first, iterator last);
		void					swap(vector &);
		void					clear();

	};

	//CONSTRUCT
	template<typename T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type &alloc)
		: _alloc(alloc),
		_capacity(0),
		_size(0),
		array(_alloc.allocate(0)){}

	template<typename T, class Alloc>
	vector<T, Alloc>::vector(const std::size_t count, const T &value, const allocator_type &alloc)
		: _alloc(alloc), 
		_capacity(count),
		_size(count),
		array(_alloc.allocate(count))
	{
		for (size_t i = 0; i < count; i++)
			array[i] = value;
	}

	template<typename T, class Alloc>
	template<class InputIt>
	vector<T, Alloc>::vector(InputIt first, InputIt last, const allocator_type &alloc,
		typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type)
		: _alloc(alloc)
	{
		_size = 0;
		for (InputIt it = first; it != last; it++)
			_size++;
		_capacity = _size;
		array = _alloc.allocate(_capacity);
		for (size_t i = 0; i < _size; i++)
			array[i] = *first++;
	}
	
	template<typename T, class Alloc>
	vector<T, Alloc>::vector(const vector<T, Alloc> &src)
		: _alloc(src._alloc),
		_capacity(src._capacity),
		_size(src._size),
		array(_alloc.allocate(_size))
	{
		insert(begin(), src.begin(), src.end());			
	}

	template<typename T, class Alloc>
	vector<T, Alloc>::~vector(){
		clear();
		_alloc.deallocate(array, _capacity);
	}

	//OPERATORS
	template<typename T, class Alloc>
	vector<T, Alloc>	&vector<T, Alloc>::operator=(vector const &rhs){
		if (rhs == *this)
			return (*this);
		this->clear();
		this->insert(this->end(), rhs.begin(), rhs.end());
		return (*this);
	}
	
	template<typename T, class Alloc>
	T	&vector<T, Alloc>::operator[](std::size_t i){
		return (array[i]);
	}

	//ITERATORS
	template<typename T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::begin(){
		return (iterator(array));
	}

	template<typename T, class Alloc>
	typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::begin() const{
		return (const_iterator(array));
	}

	template<typename T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::end(){
		return (iterator(array + _size));
	}

	template<typename T, class Alloc>
	typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::end() const{
		return (const_iterator(array + _size));
	}

	//ETC
	template<typename T, class Alloc>
	std::size_t	vector<T, Alloc>::capacity() const{
		return (_capacity);
	}

	template<typename T, class Alloc>
	std::size_t	vector<T, Alloc>::size() const{
		return (_size);
	}

	template<typename T, class Alloc>
	T	&vector<T, Alloc>::front(){
		return (array[0]);
	}
	
	template<typename T, class Alloc>
	T const	&vector<T, Alloc>::front() const{
		return (array[0]);
	}
	
	template<typename T, class Alloc>
	T	&vector<T, Alloc>::back(){
		return (array[_size]);
	}
	
	template<typename T, class Alloc>
	T const	&vector<T, Alloc>::back() const{
		return (array[_size]);
	}

	template<typename T, class Alloc>
	bool	vector<T, Alloc>::empty() const{
		return (_size == 0 ? true : false);
	}

	template<typename T, class Alloc>
	T	&vector<T, Alloc>::at(std::size_t pos){
		if (pos >= _size)
			throw std::out_of_range("out of range");
		else
			return (array[pos]);
	}

	template<typename T, class Alloc>
	T const	&vector<T, Alloc>::at(std::size_t pos) const{
		if (pos >= _size)
			throw std::out_of_range("out of range");
		else
			return (array[pos]);
	}

	// template<typename T, class Alloc>
	// T	*vector<T, Alloc>::data(){
	// 	return (array);
	// }

	// template<typename T, class Alloc>
	// T const	*vector<T, Alloc>::data() const{
	// 	return (array);
	// }
	
	template<typename T, class Alloc>
	std::size_t	vector<T, Alloc>::max_size() const{
		return (std::numeric_limits<difference_type>::max());
	}

	template<typename T, class Alloc>
	void	vector<T, Alloc>::reserve(std::size_t new_cap){	
		if (new_cap > max_size())
			throw std::length_error("");
		else if (new_cap > _capacity){
			T 			*tmp;
			std::size_t	old_cap = _capacity;
			
			tmp = _alloc.allocate(new_cap);
			_capacity = new_cap;
			for (size_t i = 0; i < _size; i++)
				tmp[i] = array[i];
			_alloc.deallocate(array, old_cap);
			array = tmp;
		}
	}

	template<typename T, class Alloc>
	void	vector<T, Alloc>::push_back(const T &value){
		if (_capacity == 0)
			reserve(1);
		else if (_size >= _capacity)
			reserve(_capacity * 2);
		array[_size] = value;
		_size++;
	}

	template<typename T, class Alloc>
	void	vector<T, Alloc>::clear(){
		_alloc.deallocate(array, _capacity);
		array = _alloc.allocate(_capacity);
		_size = 0;
	}

	template<typename T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator pos, const T &value){
		std::size_t index = 0;

		for (iterator it = begin(); it != pos; it++)
			index++;
		if (_capacity == 0)
			reserve(1);
		if (_size + 1 >= _capacity)
			reserve(_capacity * 2);
		_size++;
		for (std::size_t i = _size; i > index; i--){
			array[i] = array[i - 1];
		}
		array[index] = value;
		return (iterator(array + index));
	}

	template<typename T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator pos, std::size_t count,
			const T &value){
		std::size_t	index = 0;
		
		for (iterator it = begin(); it != pos; it++)
			index++;
		if (_capacity == 0)
			reserve(1);
		while (_size + count >= _capacity)
			reserve(_capacity * 2);
		_size += count;
		for (std::size_t i = _size; i >= index + count; i--)
			array[i] = array[i - count];
		for (size_t i = 0; i < count; i++)
			array[index + i] = value;
		return (iterator(array + index));
	}

	template<typename T, class Alloc>
	template<class InputIt>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator pos, InputIt first, InputIt last,
		typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type){
		std::size_t	index = 0;
		std::size_t	count = 0;
		
		for (iterator it = begin(); it != pos; it++)
			index++;
		for (InputIt it = first; it != last; it++)
			count++;
		if (_capacity == 0)
			reserve(1);
		while (_size + count >= _capacity)
			reserve(_capacity * 2);
		_size += count;
		for (std::size_t i = _size; i >= index + count; i--)
			array[i] = array[i - count];
		T value = *first;
		for (size_t i = 0; i < count; i++){
			array[index + i] = value;
			first++;
			value = *first;
		}
		return (iterator(array + index));
	}

	template<typename T, class Alloc>
	void	vector<T, Alloc>::assign(std::size_t count, const T &value){
		_alloc.deallocate(array, _capacity);
		array = _alloc.allocate(count);
		_size = count;
		_capacity = count;
		for (size_t i = 0; i < count; i++)
			array[i] = value;
	}
	
	template<typename T, class Alloc>
	template<class InputIt>
	void	vector<T, Alloc>::assign(InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type){
		_alloc.deallocate(array, _capacity);
		std::size_t range = 0;
		for (InputIt it = first; it != last; it++)
			range++;
		array = _alloc.allocate(range);
		_size = range;
		_capacity = range;
		for (size_t i = 0; i < range; i++)
		{
			array[i] = *first;
			first++;
		}
	}

	template<typename T, class Alloc>
	void	vector<T, Alloc>::pop_back(){
		_size--;
	}

	template<typename T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator pos){
		for (iterator it = pos; it != end() - 1; it++)
			*it = *(it + 1);
		_size--;
		return (pos);
	}

	template<typename T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last){
		std::size_t range = 0;
		for (iterator it = first; it != last; it++)
			range++;
		for (iterator it = first; last != end(); it++)
			*it = *(last++);
		_size -= range;
		return (first);
	}

//NON MEMBER 

	template <class T, class Alloc>
	bool operator== (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator first1 = lhs.begin();
		typename ft::vector<T>::const_iterator first2 = rhs.begin();
		while (first1 != lhs.end())
		{
			if (first2 == rhs.end() || *first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
		
}
#endif