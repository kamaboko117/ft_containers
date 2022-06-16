/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:11:32 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/16 18:46:19 by asaboure         ###   ########.fr       */
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
		T data;
		bool red;
		
		BstNode	*left;
		BstNode *right;
		BstNode	*parent;
	};

	template<typename T, class Alloc>
	BstNode<T>	*getNewNode(BstNode<T> *parent, typename type_identity<T>::type data, Alloc _alloc){
		BstNode<T>	*newNode = _alloc.allocate(1);
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->red = true;
		newNode->parent = parent;
		return (newNode);
	}

	template<typename T, class Compare, class Alloc>
	BstNode<T>	*BstInsert(BstNode<T> *root, BstNode<T> *parent, T &value, Compare keyComp, Alloc _alloc, BstNode<T> *last){
		if (!root || root == last){
			root = getNewNode(parent, value, _alloc);
			root->red = false;
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
		root = BstFind(root, value->first, keyComp, last);
		if (!root)
			return (root);
		if (!root->left){
			// BstNode<T> *ret = root->right;
			if (root->parent)
				BstReplace(root->parent, root->right, root->data, keyComp);
			else
				root = root->right;
			//_alloc.deallocate(root, 1);
			// root = ret;
			return (root);
		}
		else if (!root->right){
			BstNode<T> *ret = root->left;
			if (root->parent)
				BstReplace(root->parent, root->left, root->data, keyComp);
			else
				root = root->left;
			// _alloc.deallocate(root, 1);
			return (ret);
		}
		BstNode<T> *tmp = BstMinValueNode(root->right);
		root->data = tmp->data;
		root->right = BstDelete(root->right, value, keyComp, _alloc, last);
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
					u->red = false;
					root->parent->red = false;
					root->parent->parent->red = true;
					root = root->parent->parent;
				}
				else{
					if (root == root->parent->left){
						root = root->parent;
						rightRotate(root, oldRoot);
					}
					root->parent->red = false;
					root->parent->parent->red = true;
					leftRotate(root, oldRoot);
				}
			}
			else{
				BstNode<T> *u = root->parent->right; //uncle
				if (u->red){
					u->red = false;
					root->parent->red = false;
					root->parent->parent->red = true;
					root = root->parent->parent;
				}
				else{
					if (root == root->parent->right){
						root = root->parent;
						leftRotate(root, oldRoot);
					}
					root->parent->red = false;
					root->parent->parent->red = true;
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

}

#endif