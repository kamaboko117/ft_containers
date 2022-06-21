/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:11:12 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/21 14:10:00 by asaboure         ###   ########.fr       */
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
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<Key, T> > >
	class map
	{
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef pair<key_type, mapped_type>						value_type;
		typedef Compare											key_compare;
		//value_compare?
		typedef	Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef BSTiterator<BstNode<value_type>, key_compare>			iterator;
		typedef BSTconstIterator<BstNode<value_type>, key_compare>		const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	//	typedef ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef std::size_t										size_type;
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

		map			&operator=(const map &rhs);
		mapped_type	&operator[](const key_type &k);
		
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
		
		size_type	size() const;

		pair<iterator, bool>	insert(const value_type &value);
		iterator				insert(iterator position, const value_type	&val);
		template<class InputIt>
		void					insert(InputIt first, InputIt last);
		void					erase(iterator position);
		size_type				erase(const key_type &k);
		void					erase(iterator first, iterator last);
		void					clear();

		iterator				find(const key_type &k);
		const_iterator			find(const key_type &k) const;

	};

	//CONSTRUCT
	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>
		::map(const key_compare &comp, const allocator_type &alloc)
		: _alloc(alloc),
		_keyComp(comp),
		root(NULL),
		_last(_Node_Allocator().allocate(1)),
		_first(NULL)
	{
		_last->data = pair<key_type, mapped_type>();
		_last->right = NULL;
		_last->left = NULL;
		_last->parent = NULL;
		_last->red = 2;
		_first = _last;	
	}
	
	template<class Key, class T, class Compare, class Alloc>
	template<class InputIt>
	map<Key, T, Compare, Alloc>
		::map(InputIt first, InputIt last, const key_compare &comp, const allocator_type &alloc)
		: _alloc(alloc),
		_keyComp(comp),
		root(NULL),
		_last(_Node_Allocator().allocate(1)),
		_first(NULL)
	{
		_last->data = pair<key_type, mapped_type>();
		_last->right = NULL;
		_last->left = NULL;
		_last->parent = NULL;
		_last->red = 2;
		_first = _last;
		insert(first, last);			
	}
	
	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>
		::map(const map &src)
		: _alloc(src._alloc),
		_keyComp(src._keyComp),
		root(NULL),
		_last(_Node_Allocator().allocate(1)),
		_first(NULL)
	{
		_last->data = pair<key_type, mapped_type>();
		_last->right = NULL;
		_last->left = NULL;
		_last->parent = NULL;
		_last->red = 2;
		_first = _last;
		insert(src.begin(), src.end());
	}

	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>
		::~map(){
			_Node_Allocator().deallocate(_last, 1);
		}
	
	//OPERATORS
	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>	&map<Key, T, Compare, Alloc>
		::operator=(const map &rhs)
	{
		_keyComp = rhs._keyComp;
		clear();
		insert(rhs.begin(), rhs.end());
		return (*this);
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::mapped_type	&map<Key, T, Compare, Alloc>
		::operator[](const key_type &k){
		iterator	it = find(k);
		
		if (it == end())
			insert(make_pair(k, mapped_type()));
		it = find(k);
		return (it->second);
	}

	//ITERATORS
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>
		::begin(){
		return(iterator(_first));
	}
	
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>
		::begin() const{
		return(const_iterator(_first));
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>
		::end(){
			return (iterator(_last));
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>
		::end() const{
			return (const_iterator(_last));
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::reverse_iterator	map<Key, T, Compare, Alloc>
		::rbegin(){
		return (reverse_iterator(end()));
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_reverse_iterator	map<Key, T, Compare, Alloc>
		::rbegin() const{
		return (const_reverse_iterator(end()));
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::reverse_iterator	map<Key, T, Compare, Alloc>
		::rend(){
		return (reverse_iterator(begin()));
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_reverse_iterator	map<Key, T, Compare, Alloc>
		::rend() const{
		return (const_reverse_iterator(begin()));
	}
	
	//ETC
	template<class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>
		::erase(iterator position){
		BstDelete(root, &*position, _keyComp, _Node_Allocator(), _last);
	}
	
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>
		::erase(const key_type &k){
		pair<key_type, mapped_type> toDel = make_pair(k, mapped_type());
		BstDelete(root, &toDel, _keyComp, _Node_Allocator(), _last);
		return (1);
	}
		
	template<class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>
		::erase(iterator first, iterator last){
		for (iterator it = first; it != last; it++)
			BstDelete(root, &*it, _keyComp, _Node_Allocator(), _last);
	}
	
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>
		::find(const key_type &k){
		BstNode<value_type> *node = BstFind(root, k, _keyComp, _last);
		if (!node)
			return (end());
		else
			return (iterator(node));
	}
	
	template<class Key, typename T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::iterator, bool>	map<Key, T, Compare, Alloc>
		::insert(const value_type &value)
	{
		iterator it = find(value.first);
		if (it != end())
			return (ft::make_pair(it, false));
		pair<Key, mapped_type> toinsert = make_pair(value.first, value.second);
		BstNode<value_type> *node = BstInsert(root, root, toinsert, _keyComp, _Node_Allocator(), _last);

		
		if (!root){
			root = _first = node;
			root->right = _last;
			_last->parent = root;
		}
		else{
			node = BstFind(root, value.first, _keyComp, _last);
			if (_keyComp(_last->parent->data.first, node->data.first)){
				_last->parent = node;
				node->right = _last;
			}
			if (_keyComp(node->data.first, _first->data.first))
				_first = node;
		}
		iterator it2(node, _keyComp);
		pair<iterator, bool> ret = ft::make_pair(it2, true);
		return (ret);
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>
		::insert(iterator position, const value_type &val)
	{
		(void)position;
		return (insert(val).first);
	}
	
	template<class Key, typename T, class Compare, class Alloc>
	template<class InputIt>
	void	map<Key, T, Compare, Alloc>
		::insert(InputIt first, InputIt last)
	{
		for (InputIt it = first; it != last; it++)
			insert(*it);
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>
		::size() const
	{
		size_type	ret = 0;

		for (const_iterator it = begin(); it != end(); it++)
			ret++;
		return (ret);
	} 	

	template<class Key, typename T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>
		::clear()
	{
		erase(begin(), end());
	}
}

#endif