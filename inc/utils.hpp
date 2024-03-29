/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:11:32 by asaboure          #+#    #+#             */
/*   Updated: 2022/08/26 20:04:08 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include "utility.hpp"
# include <sstream>
# include <iostream>

//forced to use a RBT. using https://www.programiz.com/dsa/deletion-from-a-red-black-tree#:~:text=Red%2DBlack%20tree%20is%20a,of%20a%20red%2Dblack%20tree as reference
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
	

	template<class Key, class T>
	struct BstNode {
		typedef	ft::pair<const Key, T>	value_type;

		value_type	data;
		BstNode 	*parent;
		BstNode		*left;
		BstNode 	*right;
		int			color;

		BstNode() : data(value_type()){}
		BstNode(ft::pair<const Key, T> data) : data(data){}
	};

	template<class Key, class T, class Compare, class Alloc>
	class RedBlackTree {
	private:
		BstNode<const Key, T> *root;
		BstNode<const Key, T> *TNULL;
		Compare				compare;
		Alloc				alloc;

		// Preorder
		void preOrderHelper(BstNode< const Key, T> *node) {
			if (node != TNULL) {
				std::cout << node->data.first << " ";
				preOrderHelper(node->left);
				preOrderHelper(node->right);
			}
		}

		// Inorder
		void inOrderHelper(BstNode< const Key, T> *node) {
			if (node != TNULL) {
				inOrderHelper(node->left);
				std::cout << node->data.first << " ";
				inOrderHelper(node->right);
			}
		}

		// Post order
		void postOrderHelper(BstNode< const Key, T> *node) {
			if (node != TNULL) {
				postOrderHelper(node->left);
				postOrderHelper(node->right);
				std::cout << node->data.first << " ";
			}
		}

		BstNode< const Key, T> *searchTreeHelper(BstNode< const Key, T> *node, Key key) {
			if (node == TNULL || (!compare(key, node->data.first) && !compare(node->data.first, key)))
				return node;
			if (compare(key, node->data.first))
				return searchTreeHelper(node->left, key);
			return searchTreeHelper(node->right, key);
		}

		const BstNode< const Key, T> *searchTreeHelper(const BstNode< const Key, T> *node, Key key) const{
			if (node == TNULL || (!compare(key, node->data.first) && !compare(node->data.first, key)))
				return node;
			if (compare(key, node->data.first))
				return searchTreeHelper(node->left, key);
			return searchTreeHelper(node->right, key);
		}

		// For balancing the tree after deletion
		void deleteFix(BstNode< const Key, T> *x) {
			BstNode< const Key, T> *s;
			while (x != root && x->color == 0) {
				if (x == x->parent->left) {
					s = x->parent->right;
					if (s->color == 1) {
						s->color = 0;
						x->parent->color = 1;
						leftRotate(x->parent);
						s = x->parent->right;
					}
					if (s->left->color == 0 && s->right->color == 0) {
						s->color = 1;
						x = x->parent;
					} else {
						if (s->right->color == 0) {
							s->left->color = 0;
							s->color = 1;
							rightRotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = 0;
						s->right->color = 0;
						leftRotate(x->parent);
						x = root;
					}
				} else {
					s = x->parent->left;
					if (s->color == 1) {
						s->color = 0;
						x->parent->color = 1;
						rightRotate(x->parent);
						s = x->parent->left;
					}
					if (s->right->color == 0 && s->right->color == 0) {
						s->color = 1;
						x = x->parent;
					} else {
						if (s->left->color == 0) {
							s->right->color = 0;
							s->color = 1;
							leftRotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = 0;
						s->left->color = 0;
						rightRotate(x->parent);
						x = root;
					}
				}
			}
			x->color = 0;
		}

		void rbTransplant(BstNode<const Key, T> *u, BstNode<const Key, T> *v) {
			if (!u->parent)
				root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void deleteBSTNodeHelper(BstNode<const Key, T> *node, Key key) {
			BstNode<const Key, T> *z = TNULL;
			BstNode<const Key, T> *x, *y;

			while (node && node != TNULL) {
				if (!compare(node->data.first, key) && !compare(key, node->data.first))
					z = node;
				if (!compare(key, node->data.first)) 
					node = node->right;
				else
					node = node->left;
			}
			if (z == TNULL) {
				std::cout << "Key not found in the tree" << std::endl;
				return ;
			}
			y = z;
			int y_original_color = y->color;
			if (z->left == TNULL) {
				x = z->right;
				rbTransplant(z, z->right);
			} else if (z->right == TNULL) {
				x = z->left;
				rbTransplant(z, z->left);
			} else {
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else {
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			alloc.deallocate(z, 1);
			if (y_original_color == 0)
				deleteFix(x);
		}

		// For balancing the tree after insertion
		void insertFix(BstNode<const Key, T> *k) {
			BstNode<const Key, T> *u;
			while (k->parent->color == 1) {
				if (k->parent == k->parent->parent->right) {
					u = k->parent->parent->left;
					if (u->color == 1) {
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					} else {
						if (k == k->parent->left) {
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						leftRotate(k->parent->parent);
					}
				} else {
					u = k->parent->parent->right;
					if (u->color == 1) {
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					} else {
						if (k == k->parent->right) {
							k = k->parent;
							leftRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						rightRotate(k->parent->parent);
					}
				}
				if (k == root)
					break;
			}
			root->color = 0;
		}

		void printHelper(BstNode<const Key, T> *root, std::string indent, bool last) {
			if (root != TNULL) {
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "   ";
				} else {
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->data.first << "(" << sColor << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		public:
		RedBlackTree(Compare compare, Alloc alloc) : compare(compare), alloc(alloc) {
			TNULL = alloc.allocate(1);
			alloc.construct(TNULL, BstNode<const Key, T>());
			TNULL->color = 0;
			TNULL->left = NULL;
			TNULL->right = NULL;
			root = TNULL;
			root->parent = NULL;
		}

		RedBlackTree	&operator=(const RedBlackTree *src){
			TNULL = src->TNULL;
			root = src->root;
			alloc = src->alloc;
			compare = src->compare;
		}

		~RedBlackTree(){
				alloc.deallocate(TNULL, 1);
		}

		void preorder() {
			preOrderHelper(this->root);
		}

		void inorder() {
			inOrderHelper(this->root);
		}

		void postorder() {
			postOrderHelper(this->root);
		}

		BstNode<const Key, T> *searchTree(Key k) {
			return searchTreeHelper(this->root, k);
		}

		const BstNode<const Key, T> *searchTree(Key k) const{
			return searchTreeHelper(this->root, k);
		}

		BstNode<const Key, T> *minimum(BstNode<const Key, T> *node) {
			if (node == TNULL)
				return (NULL);
			while (node != TNULL && node->left != TNULL)
				node = node->left;
			return node;
		}

		const BstNode<const Key, T> *minimum(BstNode<const Key, T> const *node) const{
			if (node == TNULL)
				return (NULL);
			while (node != TNULL && node->left != TNULL)
				node = node->left;
			return node;
		}

		BstNode<const Key, T> *maximum(BstNode<const Key, T> *node) {
			while (node != TNULL && node->right != TNULL)
				node = node->right;
			return node;
		}

		const BstNode<const Key, T> *maximum(BstNode<const Key, T> const *node) const{
			while (node != TNULL && node->right != TNULL)
				node = node->right;
			return node;
		}

		BstNode<const Key, T> *successor(BstNode<const Key, T> *x) {
			if (x->right != TNULL)
				return minimum(x->right);
			BstNode<const Key, T> *y = x->parent;
			while (y != TNULL && x == y->right) {
				x = y;
				y = y->parent;
			}
			return y;
		}

		BstNode<const Key, T> *predecessor(BstNode<const Key, T> *x) {
			if (x->left != TNULL)
				return maximum(x->left);
			BstNode<const Key, T> *y = x->parent;
			while (y != TNULL && x == y->left) {
				x = y;
				y = y->parent;
			}
			return y;
		}

		void leftRotate(BstNode<const Key, T> *x) {
			BstNode<const Key, T> *y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (!x->parent)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		void rightRotate(BstNode<const Key, T> *x) {
			BstNode< const Key, T> *y = x->left;
			x->left = y->right;
			if (y->right != TNULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (!x->parent)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		// Inserting a node
		void insert(pair<const Key, T> value) {
			BstNode< const Key, T> *node = alloc.allocate(1);
			alloc.construct(node, BstNode< const Key, T>(value));
			node->parent = NULL;
			node->left = TNULL;
			node->right = TNULL;
			node->color = 1;

			BstNode< const Key, T> *y = NULL;
			BstNode< const Key, T> *x = this->root;

			while (x != TNULL) {
				y = x;
				if (compare(node->data.first, x->data.first))
					x = x->left;
				else
					x = x->right;
			}
			node->parent = y;
			if (!y)
				root = node;
			else if (compare(node->data.first, y->data.first))
				y->left = node;
			else
				y->right = node;
			if (!node->parent) {
				node->color = 0;
				return ;
			}
			if (!node->parent->parent)
				return ;
			insertFix(node);
		}

		BstNode<const Key, T> *getRoot() {
			return this->root;
		}

		const BstNode<const Key, T> *getRoot() const{
			return this->root;
		}

		BstNode<const Key, T> *getTNULL() {
			return this->TNULL;
		}

		const BstNode<const Key, T> *getTNULL() const{
			return this->TNULL;
		}

		void	setTNULL(BstNode<const Key, T> *node){
			TNULL = node;
		}

		void	setRoot(BstNode<const Key, T> *node){
			root = node;
		}

		void deleteBSTNode(Key data) {
			deleteBSTNodeHelper(this->root, data);
		}

		void printTree() {
			if (root)
				printHelper(this->root, "", true);
		}
	};

	template <typename T>
	std::string NumberToString(T Number )
	{
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}
}

#endif