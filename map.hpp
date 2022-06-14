/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:11:12 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/14 14:52:33 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <functional>
# include "iterator.hpp"
# include "utility.hpp"
# include "utils.hpp"
# include "BSTiterator.hpp"

namespace ft
{

//MAP	
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair<key_type, mapped_type>					value_type;
		typedef Compare										key_compare;
		//value_compare?
		typedef	Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef BSTiterator<value_type, key_compare>		iterator;
		//const_iterator
		//reverse_iterator
		//const_reverse_iterator
		//difference_type
		typedef std::size_t							size_type;
	private:
		allocator_type		_alloc;
		key_compare			_keyComp;
		BstNode<value_type>	*root;
		BstNode<value_type> *_last;
		BstNode<value_type> *_first;
		
		typedef typename allocator_type::template rebind<BstNode<value_type> >::other _Node_Allocator;

	public:
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		template<class InputIt>
		map(InputIt first, InputIt last, const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
		map(const map &src);
		~map();

		mapped_type	&operator[](const key_type &k);
		
		iterator	begin();
		iterator	end();
		
		pair<iterator, bool>	insert(const value_type &value);
		iterator				find(const key_type &k);
	};

	//CONSTRUCT
	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type &alloc)
		: _alloc(alloc),
		_keyComp(comp),
		root(NULL),
		_last(NULL),
		_first(NULL){}
	
	// template<class Key, class T, class Compare, class Alloc>
	// template<class InputIt>
	// map<Key, T, Compare, Alloc>::map(InputIt first, InputIt last, const key_compare &comp, const allocator_type &alloc)
	// 	: _alloc(alloc),
	// 	_keyComp(comp){}
	
	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map(){}
	
	//OPERATORS
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::mapped_type	&map<Key, T, Compare, Alloc>::operator[](const key_type &k){
		iterator	it = find(k);
		
		if (it == end())
			insert(make_pair(k, mapped_type()));
		it = find(k);
		return (it->second);
	}

	//ITERATORS
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::begin(){
		return(iterator(_first));
	}
	
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::end(){
		if (!_last)
			return (iterator(_last));
		return(iterator(_last->right));
	}

	//ETC
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::find(const key_type &k){
		BstNode<value_type> *node = BstFind(root, k, _keyComp);

		if (!node)
			return (end());
		else
			return (iterator(node));
	}
	
	template<class Key, typename T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::iterator, bool>	map<Key, T, Compare, Alloc>::insert(const value_type &value){
		iterator it = find(value.first);
		if (it != end())
			return (ft::make_pair(it, false));
		pair<Key, mapped_type> toinsert = make_pair(value.first, value.second);
		BstNode<value_type> *node = BstInsert(root, root, toinsert, _keyComp, _Node_Allocator());
		if (!root)
			root = _first = _last = node;
		else{
			node = BstFind(root, value.first, _keyComp);
			if (_keyComp(_last->data.first, node->data.first))
				_last = node;
			if (_keyComp(node->data.first, _first->data.first))
				_first = node;
		}
		iterator it2(node, _keyComp);
		pair<iterator, bool> ret = ft::make_pair(it2, true);
		return (ret);
	}
}

#endif