/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:11:12 by asaboure          #+#    #+#             */
/*   Updated: 2022/07/18 18:33:50 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <functional>
# include "./inc/iterator.hpp"
# include "./inc/utility.hpp"
# include "./inc/utils.hpp"
# include "./inc/BSTiterator.hpp"
# include "./inc/algorithm.hpp"

namespace ft
{

//MAP	
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef pair<const key_type, mapped_type>						value_type;
		typedef Compare													key_compare;
		typedef	Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef BSTiterator<BstNode<value_type>, key_compare>			iterator;
		typedef BSTconstIterator<BstNode<value_type>, key_compare>		const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef std::size_t												size_type;
		class	value_compare
		{
			//https://cplusplus.com/reference/map/map/value_comp/
			friend class map<key_type, mapped_type, key_compare, Alloc>;
				
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
				
			public:
				typedef bool 		result_type;
  				typedef value_type	first_argument_type;
  				typedef value_type	second_argument_type;
				
				bool operator() (const value_type& x, const value_type& y) const{
					return (comp(x.first, y.first));
				}
			};

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
		
		bool		empty() const;
		size_type	size() const;
		size_type	max_size() const;

		pair<iterator, bool>	insert(const value_type &value);
		iterator				insert(iterator position, const value_type	&val);
		template<class InputIt>
		void					insert(InputIt first, InputIt last);
		void					erase(iterator position);
		size_type				erase(const key_type &k);
		void					erase(iterator first, iterator last);
		void					swap(map &x);
		void					clear();

		key_compare		key_comp() const;
		value_compare	value_comp() const;

		iterator								find(const key_type &k);
		const_iterator							find(const key_type &k) const;
		size_type								count(const key_type &k) const;
		iterator								lower_bound(const key_type &k);
		const_iterator							lower_bound(const key_type &k) const;
		iterator								upper_bound(const key_type &k);
		const_iterator							upper_bound(const key_type &k) const;
		pair<iterator, iterator>				equal_range (const key_type &k);
		pair<const_iterator, const_iterator>	equal_range (const key_type &k) const;
	
		allocator_type	get_allocator() const;
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
		_alloc.construct(&_last->data, value_type());
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
		_alloc.construct(&_last->data, value_type());
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
		_alloc.construct(&_last->data, value_type());
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
			clear();
			_Node_Allocator().deallocate(_last, 1);
		}
	
	//OPERATORS
	template<class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>	&map<Key, T, Compare, Alloc>
		::operator=(const map &rhs)
	{
		_keyComp = rhs._keyComp;
		clear();
		_alloc.construct(&_last->data, value_type());
		_last->right = NULL;
		_last->left = NULL;
		_last->parent = NULL;
		_last->red = 2;
		_first = _last;
		insert(rhs.begin(), rhs.end());
		return (*this);
	}

	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::mapped_type	&map<Key, T, Compare, Alloc>
		::operator[](const key_type &k)
	{
		iterator	it = find(k);
		
		if (it == end())
			insert(ft::make_pair(k, mapped_type()));
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
		::erase(iterator position)
	{
		erase(position->first);
	}
	
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>
		::erase(const key_type &k)
	{
		BstNode<value_type>	*tmp;
		BstNode<value_type> *node = BstFind(root, k, _keyComp, _last);
		_Node_Allocator		nodeAlloc;
		
		if (!node)
			return (0);
		if (!_keyComp(k, _first->data.first) && !_keyComp(_first->data.first, k))
			_first = BstNextNode( _first, _keyComp);
		if (!_keyComp(k, _last->parent->data.first) && !_keyComp(_last->parent->data.first, k))
			_last->parent = BstPreviousNode(_last->parent, _keyComp);
		value_type toDel = ft::make_pair(k, mapped_type());
		tmp = BstDelete(root, &toDel, _keyComp, nodeAlloc, _last);
		if (!tmp){
			_first = _last;
			nodeAlloc.destroy(node);
			nodeAlloc.deallocate(node, 1);
			return (1);
		}
		if (!_keyComp(k, _first->data.first) && !_keyComp(_first->data.first, k))
			_first = tmp;
		if (!_keyComp(k, root->data.first) && !_keyComp(root->data.first, k)){
			root = tmp;
			root->parent = NULL;
		}
		if (!_last->parent){
			root = NULL;
			_first = _last;
		}
		nodeAlloc.destroy(node);
		nodeAlloc.deallocate(node, 1);
		return (1);
	}
		
	template<class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>
		::erase(iterator first, iterator last)
	{
		while (first != last)
			this->erase((*(first++)).first);
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
	
	template<class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>
		::find(const key_type &k) const
	{
		BstNode<value_type> *node = BstFind(root, k, _keyComp, _last);
		if (!node)
			return (end());
		else
			return (const_iterator(node));
	}
	
	template<class Key, typename T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::iterator, bool>	map<Key, T, Compare, Alloc>
		::insert(const value_type &value)
	{
		iterator it = find(value.first);
		if (it != end())
			return (ft::make_pair(it, false));
		value_type toinsert = ft::make_pair(value.first, value.second);
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

	template<class Key, typename T, class Compare, class Alloc>
	bool	map<Key, T, Compare, Alloc>
		::empty() const
	{
		return (!size());
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>
		::max_size() const
	{
		return (_Node_Allocator().max_size());
	}

	template<class Key, typename T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>
		::swap(map &x)
	{
		BstNode<value_type>	*tmp = root;
		root = x.root;
		x.root = tmp;
		tmp = _first;
		_first = x._first;
		x._first = tmp;
		tmp = _last;
		_last = x._last;
		x._last = tmp;
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::key_compare	map<Key, T, Compare, Alloc>
		::key_comp() const
	{
		return (key_compare());
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::value_compare	map<Key, T, Compare, Alloc>
		::value_comp() const
	{
		return (value_compare(key_compare()));
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>
		::count(const key_type &k) const
	{
		for (const_iterator it = begin(); it != end(); it++)
		{
			if (!_keyComp(it->first, k) && !_keyComp(k, it->first))
				return (1);
		}
		return (0);
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>
		::lower_bound(const key_type &k)
	{
		iterator	it = begin();
		for (; it != end(); it++){
			if (!_keyComp(it->first, k))
				return (it);
		}
		return (it);
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>
		::lower_bound(const key_type &k) const
	{
		const_iterator	it = begin();
		for (; it != end(); it++){
			if (!_keyComp(it->first, k))
				return (it);
		}
		return (it);
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>
		::upper_bound(const key_type &k)
	{
		iterator	it = begin();
		for (; it != end(); it++){
			if (_keyComp(k, it->first))
				return (it);
		}
		return (it);
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>
		::upper_bound(const key_type &k) const
	{
		const_iterator	it = begin();
		for (; it != end(); it++){
			if (_keyComp(k, it->first))
				return (it);
		}
		return (it);
	}

	template<class Key, typename T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>	map<Key, T, Compare, Alloc>
		::equal_range(const key_type &k)
	{
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}
	
	template<class Key, typename T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator>	map<Key, T, Compare, Alloc>
		::equal_range(const key_type &k) const
	{
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}

	template<class Key, typename T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::allocator_type	map<Key, T, Compare, Alloc>
		::get_allocator() const
	{
		return (allocator_type(_alloc));
	}

//NON MEMBER

	template<class Key, typename T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs){
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator first1 = lhs.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator first2 = rhs.begin();
		while (first1 != lhs.end())
		{
			if (first2 == rhs.end() || *first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template<class Key, typename T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs){
		return (!(lhs == rhs));
	}

	template<class Key, typename T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs){
		return (ft::lexicographical_compare(lhs.begin(),  lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, typename T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs){
		return(!(rhs < lhs));
	}
	
	template<class Key, typename T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs){
		return(rhs < lhs);
	}

	template<class Key, typename T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs){
		return(!(lhs < rhs));
	}
	
}

#endif