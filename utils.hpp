/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:11:32 by asaboure          #+#    #+#             */
/*   Updated: 2022/07/16 16:53:16 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "utility.hpp"

#include <iostream>
// static class nullptr_t
// {
// public:
//     template<class T>
//     operator T*() const { return (0); }

//     template<class C, class T>
//     operator T C::*() const { return (0); }
		
// private:
//     void operator&() const;

// } u_nullptr = {};

namespace ft
{

	template<typename T>
	struct type_identity
	{
		typedef T type;
	};


// v_iterator
	template<typename T>
	class v_iterator
	{
	public:
		typedef T 				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef	value_type*		pointer;
		typedef value_type&		reference;
		typedef v_iterator		iterator_category;
	private:
		T	*ptr;
	public:
		v_iterator(){}
		v_iterator(T *ptr)
			: ptr(ptr){}
		template<typename U>
		v_iterator(const v_iterator<U> &src)
		: ptr(src.base()){}
		~v_iterator(){}
		
		v_iterator	&operator=(const v_iterator &rhs){
			if (this == &rhs)
				return (*this);
			ptr = rhs.ptr;
			return (*this);
		}
		v_iterator	&operator++(){
			this->ptr++;
			return (*this);
		}
		v_iterator	operator++(int){
			v_iterator it = *this;
			++(*this);
			return (it);
		}
		v_iterator	&operator--(){
			ptr--;
			return (*this);
		}
		v_iterator	operator--(int){
			v_iterator it = *this;
			--(*this);
			return (it);
		}
		T			&operator*() const{
			return (*ptr);
		}
		T			&operator[](difference_type i){
			return (ptr[i]);
		}
		T			*operator->(){
			return (ptr);
		}
		bool		operator==(const v_iterator &rhs) const{
			return (ptr == rhs.ptr);
		}
		bool		operator!=(const v_iterator &rhs) const{
			return (ptr != rhs.ptr);
		}
		v_iterator	operator+(std::size_t i) const{
			return (v_iterator(ptr + i));
		}
		v_iterator	operator-(std::size_t i) const{
			return (v_iterator(ptr - i));
		}
		v_iterator	&operator+=(difference_type n){
			ptr += n;
			return (*this);
		}
		v_iterator	&operator-=(difference_type n){
			ptr -= n;
			return (*this);
		}
		T	*base() const{
			return (ptr);
		}
	};

// iteraror non member operators
	template<typename T>
	bool	operator==(const v_iterator<T> lhs, const v_iterator<T> rhs){
        return (lhs.base() == rhs.base());
    }
	template<typename T_L, typename T_R>
    bool	operator==(const v_iterator<T_L> lhs, const v_iterator<T_R> rhs)
    {
        return (lhs.base() == rhs.base());
    }
	template<typename T>
	bool	operator!=(const v_iterator<T> lhs, const v_iterator<T> rhs)
    {
        return (lhs.base() != rhs.base());
    }
	template<typename T_L, typename T_R>
    bool	operator!=(const v_iterator<T_L> lhs, const v_iterator<T_R> rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template<typename T>
    bool	operator<(const v_iterator<T> lhs, const v_iterator<T> rhs)
    {
        return (lhs.base() < rhs.base());
    }
	template<typename T_L, typename T_R>
    bool	operator<(const v_iterator<T_L> lhs, const v_iterator<T_R> rhs)
    {
        return (lhs.base() < rhs.base());
    }
	template<typename T>
    bool	operator>(const v_iterator<T> lhs, const v_iterator<T> rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template<typename T_L, typename T_R>
    bool	operator>(const v_iterator<T_L> lhs, const v_iterator<T_R> rhs)
    {
        return (lhs.base() > rhs.base());
    }
	template<typename T>
    bool	operator<=(const v_iterator<T> lhs, const v_iterator<T> rhs)
    {
        return (lhs.base() <= rhs.base());
    }
	template<typename T_L, typename T_R>
    bool	operator<=(const v_iterator<T_L> lhs, const v_iterator<T_R> rhs)
    {
        return (lhs.base() <= rhs.base());
    }
	template<typename T>
    bool	operator>=(const v_iterator<T> lhs, const v_iterator<T> rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template<typename T_L, typename T_R>
    bool	operator>=(const v_iterator<T_L> lhs, const v_iterator<T_R> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

	// template<typename T>	
	// typename v_iterator<T>::difference_type	operator+(const v_iterator<T> lhs, const v_iterator<T> rhs){
    //     return (lhs.base() + rhs.base());
    // }
	// template<typename T_L, typename T_R>
    // typename v_iterator<T_L>::difference_type	operator+(const v_iterator<T_L> lhs, const v_iterator<T_R> rhs){
    //     return (lhs.base() + rhs.base());
    // }
	template<typename T>
    ft::v_iterator<T>	operator+(typename ft::v_iterator<T>::difference_type n, typename ft::v_iterator<T>& rai)
    {
		return (&(*rai) + n);
	}
	template<typename T>
    typename v_iterator<T>::difference_type	operator-(const v_iterator<T> lhs, const v_iterator<T> rhs){
        return (lhs.base() - rhs.base());
    }
	template<typename T_L, typename T_R>
    typename v_iterator<T_L>::difference_type	operator-(const v_iterator<T_L> lhs, const v_iterator<T_R> rhs){
        return (lhs.base() - rhs.base());
    }
	

//BST
//https://www.youtube.com/watch?v=COZK7NATh4k
//TRUE = RED
	template<class T>
	struct BstNode
	{
		typedef	T	value_type;

		T data;
		int red;
		
		BstNode	*left;
		BstNode *right;
		BstNode	*parent;

		BstNode(T data) : data(data){}
	};

	template<typename T, class Alloc>
	BstNode<T>	*getNewNode(BstNode<T> *parent, typename type_identity<T>::type data, Alloc _alloc){
		BstNode<T>	*newNode = _alloc.allocate(1);
		_alloc.construct(newNode, BstNode<T>(data));
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->red = 1;
		newNode->parent = parent;
		return (newNode);
	}

	template<typename T, class Compare, class Alloc>
	BstNode<T>	*BstInsert(BstNode<T> *root, BstNode<T> *parent, T &value, Compare keyComp, Alloc _alloc, BstNode<T> *last){
		if (!root || root == last){
			root = getNewNode(parent, value, _alloc);
			root->red = 0;
			return (root);
		}
		else if (keyComp(value.first, root->data.first))
			root->left = BstInsert(root->left, root, value, keyComp, _alloc, last);
		else
			root->right = BstInsert(root->right, root, value, keyComp, _alloc, last);
		return (root);
	}

	template<typename T>
	BstNode<T>	*BstMinValueNode(BstNode<T> *node)
	{
		BstNode<T> *current = node;
	
		while (current && current->left)
			current = current->left;
		return current;
	}
	
	template<typename T, class Compare>
	void	BstReplace(BstNode<T> *parent, BstNode<T> *src, T &value, Compare comp){
		if (comp(value.first, parent->data.first))
			parent->left = src;
		else
			parent->right =src;
		if (src) 
			src->parent = parent;
	}

	//https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
	template<typename T, class Compare, class Alloc>
	BstNode<T>	*BstDelete(BstNode<T> *root, T *value, Compare keyComp, Alloc _alloc, BstNode<T> *last){
		if (!root || root->red == 2)
			return (root);
		// std::cout << "root: " << root->data.first << " value: " << value->first << std::endl;
		if (keyComp(value->first, root->data.first))
			root->left = BstDelete(root->left, value, keyComp, _alloc, last);
		else if (keyComp(root->data.first, value->first))
			root->right = BstDelete(root->right, value, keyComp, _alloc, last);
		else {
			if (!root->left && !root->right)
				return (NULL);
			else if (!root->left){
				root->right->parent = root->parent;
				return (root->right);
			}
			else if (!root->right){
				root->left->parent = root->parent;
				return (root->left);
			}
				
			BstNode<T> *tmp = BstMinValueNode(root->right);
			BstNode<T> *old = root;
			root = getNewNode(old->parent, tmp->data, _alloc);
			root->parent = old->parent;
			root->left = old->left;
			root->left->parent = root;
			root->red = old->red;
			root->right = BstDelete(old->right, &tmp->data, keyComp, _alloc, last);
			if (root->right)
				root->right->parent = root;
		}
		return (root);
	}

	template<typename T>
	void	leftRotate(BstNode<T> *x, BstNode<T> *root){
		BstNode<T> *y = x->right;
		x->right = y->left;
		if (y->left)
			y->left->parent = x;
		y->parent = x->parent;
		if (!(x->parent))
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	template<typename T>
	void	rightRotate(BstNode<T> *x, BstNode<T> *root){
		BstNode<T> *y = x->left;
		x->left = y->right;
		if (y->right)
			y->right->parent = x;
		y->parent = x->parent;
		if (!(x->parent))
			root = y;
		else if (x == x->parent->left)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	//https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
	template<typename T, class Compare, class Alloc>
	BstNode<T>	*RBInsert(BstNode<T> *root, T &value, Compare keyComp, Alloc _alloc){
		BstNode<T>	*oldRoot = root;
		root = BstInsert(root, value, keyComp, _alloc);
		while (root->parent->red){
			if (root->parent == root->parent->parent->right){
				BstNode<T> *u = root->parent->left; //uncle
				if (u->red){
					u->red = 0;
					root->parent->red = 0;
					root->parent->parent->red = 1;
					root = root->parent->parent;
				}
				else{
					if (root == root->parent->left){
						root = root->parent;
						rightRotate(root, oldRoot);
					}
					root->parent->red = 0;
					root->parent->parent->red = 1;
					leftRotate(root, oldRoot);
				}
			}
			else{
				BstNode<T> *u = root->parent->right; //uncle
				if (u->red){
					u->red = 0;
					root->parent->red = 0;
					root->parent->parent->red = 1;
					root = root->parent->parent;
				}
				else{
					if (root == root->parent->right){
						root = root->parent;
						leftRotate(root, oldRoot);
					}
					root->parent->red = 0;
					root->parent->parent->red = 1;
					rightRotate(root, oldRoot);
				}
			}
			if (root == oldRoot)
				break ;
		}
		oldRoot->red = false;
	}
	
	template<typename T, class Compare>
	bool	BstSearch(BstNode<T> *root, const T value, Compare keyComp){
		if (!root)
			return (false);
		else if (!keyComp(value.first, root->data.first) && !keyComp(value.first, root->data.first))
			return (true);
		else if (keyComp(value.first, root->data.first))
			return (BstSearch(root->left, value, keyComp));
		else
			return (BstSearch(root->right, value, keyComp));
	}

	template<class Key, typename T, class Compare>
	BstNode<T>	*BstFind(BstNode<T> *root, const Key &value, Compare keyComp, BstNode<T> *last){
		if (!root || root == last)
			return (NULL);
		else if (!keyComp(value, root->data.first) && !keyComp(root->data.first, value))
			return (root);
		else if (keyComp(value, root->data.first))
			return (BstFind(root->left, value, keyComp, last));
		else
			return (BstFind(root->right, value, keyComp, last));
	}

	template<class Key, typename T>
	int BstHeight(BstNode<T> *root)
	{
		if (!root)
			return 0;
		else{
			int l = height(root->left);
			int r = height(root->right);
			if (l > r)
				return (l + 1);
			else
				return r + 1;
		}
	}

	template<typename T, class Compare>
	BstNode<T>	*BstNextNode(BstNode<T> *node, Compare comp){
		BstNode<T> *current = node;
		if (node->right && comp(node->data.first, node->right->data.first)){
			current = node->right;
			while (current->left && comp(node->data.first, current->left->data.first))
				current = current->left;
		}
		else{
			if (!(node->parent)){
				node = node->right;
				return (node);
			}
			while (current->parent){
				current = current->parent;
				if (comp(node->data.first, current->data.first))
					break ;
			}
		}
		if (comp(node->data.first, current->data.first))
			node = current;
		else
			node = node->right;
		return (node);
	}

	template<typename T, class Compare>
	BstNode<T>	*BstPreviousNode(BstNode<T> *node, Compare comp){
		BstNode<T>	*current = node;
		if (node->red == 2){
			node = node->parent;
			return (node);
		}
		if (node->left && comp(node->left->data.first, node->data.first))
			current = node->left;
		else{
			while(current->parent && comp(node->data.first, current->parent->data.first))
				current = current->parent;
		}
		if (node == current)
			node = node->parent;
		else
			node = current;
		return (node);
	}
}

#endif