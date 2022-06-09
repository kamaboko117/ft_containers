/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:11:32 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/09 20:04:51 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "utility.hpp"

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

// v_iterator
	template<typename T>
	class v_iterator
	{
	public:
		typedef T 				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef	value_type*		pointer;
		typedef value_type&		reference;
		typedef v_iterator		v_iterator_category;
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
	template<class T>
	struct BstNode
	{
		T data;

		BstNode	*left;
		BstNode *right;
		BstNode	*parent;
	};

	template<typename T, class Alloc>
	BstNode<T>	*getNewNode(BstNode<T> *root, T data, Alloc _alloc){
		BstNode<T>	*newNode = _alloc.allocate(1);
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = root;
		return (newNode);
	}

	template<typename T, class Compare, class Alloc>
	BstNode<T>	*BstInsert(BstNode<T> *root, T value,
		Compare keyComp, Alloc _alloc){
		if (!root)
			return (root = getNewNode(root, value, _alloc));
		else if (keyComp(value.first, root->data.first))
			root->left = BstInsert(root->left, value, keyComp, _alloc);
		else
			root->right = BstInsert(root->right, value, keyComp, _alloc);
		return (root);
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
	BstNode<T>	*BstFind(BstNode<T> *root, const Key &value, Compare keyComp){
		if (!root)
			return (NULL);
		else if (!keyComp(value, root->data.first) && !keyComp(value, root->data.first))
			return (root);
		else if (keyComp(value, root->data.first))
			return (BstFind(root->left, value, keyComp));
		else
			return (BstFind(root->right, value, keyComp));
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