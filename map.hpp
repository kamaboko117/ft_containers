/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:11:12 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/07 15:01:25 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <functional>
# include "iterator.hpp"
# include "utility.hpp"
# include "utils.hpp"

namespace ft
{

//MAP	
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair<const key_type, mapped_type>			value_type;
		typedef Compare										key_compare;
		//value_compare?
		typedef	Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		//iterator
		//const_iterator
		//reverse_iterator
		//const_reverse_iterator
		//difference_type
		typedef std::size_t							size_type;
	private:
		allocator_type	_alloc;
		key_compare		_keyComp;
		BstNode<Key, T>	*root;
		
		BstNode<Key, T>	*getNewNode(pair<Key, T> data);

	public:
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		template<class InputIt>
		map(InputIt first, InputIt last, const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
		map(const map &src);
		~map();

		void	insert(const value_type &value);
	};

	//CONSTRUCT
	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type &alloc)
		: _alloc(alloc),
		_keyComp(comp),
		root(NULL){}
	
	// template<class Key, class T, class Compare, class Alloc>
	// template<class InputIt>
	// map<Key, T, Compare, Alloc>::map(InputIt first, InputIt last, const key_compare &comp, const allocator_type &alloc)
	// 	: _alloc(alloc),
	// 	_keyComp(comp){}
	
	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map(){}
	
	//PRIVATE
	

	//ETC
	// template<class Key, typename T, class Compare, class Alloc>
	// void	map<Key, T, Compare, Alloc>::insert(const value_type &value){
		
	// }
}

#endif