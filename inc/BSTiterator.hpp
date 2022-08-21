/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTiterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:36:48 by asaboure          #+#    #+#             */
/*   Updated: 2022/08/21 20:45:37 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTITERATOR_HPP
# define BSTITERATOR_HPP

namespace ft
{
	
	// BSTiterator
	template<typename T, class Compare>
	class BSTiterator
	{
	public:
		typedef typename T::value_type 				value_type;
		typedef typename value_type::first_type		key;
		typedef typename value_type::second_type	mapped_type;
		typedef std::ptrdiff_t						difference_type;
		typedef value_type*							pointer;
		typedef value_type&							reference;
		typedef BSTiterator							iterator_category;

		T			*node;
		T			*TNULL;
		T			*max;
		Compare		comp;

		BSTiterator(const Compare &comp = Compare())
			: node(NULL),
			TNULL(NULL),
			max(NULL),
			comp(comp){}
		BSTiterator(BstNode<const key, mapped_type> *node, BstNode<const key, mapped_type> *TNULL, BstNode<const key, mapped_type> *max, const Compare &comp = Compare())
			: node(node),
			TNULL(TNULL),
			max(max),
			comp(comp){}
		template<typename U, class Comp>
		BSTiterator(const BSTiterator<U, Comp> &src)
			: node(src.node),
			TNULL(src.TNULL),
			max(src.max),
			comp(src.comp){}
		~BSTiterator(){}
		
		BSTiterator	&operator=(const BSTiterator &rhs){
			if (this == &rhs)
				return (*this);
			node = rhs.node;
			TNULL = rhs.TNULL;
			max = rhs.max;
			comp = rhs.comp;
			return (*this);
		}
		BSTiterator	&operator++(){
			if (!node)
				return (*this);
			BstNode<const key, mapped_type> *current = node;
			if (node->right != TNULL && comp(node->data.first, node->right->data.first)){
				current = node->right;
				while (current->left != TNULL && comp(node->data.first, current->left->data.first))
					current = current->left;
			}
			else{
				while (current->parent){
					current = current->parent;
					if (comp(node->data.first, current->data.first))
						break ;
				}
			}
			if (comp(node->data.first, current->data.first))
				node = current;
			else
				node = current->parent;
			return (*this);
		}
		BSTiterator	operator++(int){
			BSTiterator it = *this;
			++(*this);
			return (it);
		}
		BSTiterator	&operator--(){
			BstNode<const key, mapped_type>	*current = node;
			if (!node){
				node = max;
				return (*this);
			}
			if (node->left != TNULL && comp(node->left->data.first, node->data.first)){
				current = node->left;
				while (current->right != TNULL && comp(current->right->data.first, node->data.first))
					current = current->right;
				node = current;
				return (*this);
			}
			else{
				while(current->parent){
					current = current->parent;
					if (comp(current->data.first, node->data.first)){
						node = current;
						return (*this);
					}
				}
			}
			// at this point current is root ==> get bottom left node = min
			while (current->left && current->left != TNULL)
				current = current->left;
			node = current;
			return (*this);
		}
		BSTiterator	operator--(int){
			BSTiterator it = *this;
			--(*this);
			return (it);
		}
		value_type	&operator*() const{
			return (node->data);
		}
		value_type	*operator->() const{
			return (&node->data);
		}
		bool		operator==(const BSTiterator &rhs) const{
			return (node == rhs.node);
		}
		bool		operator!=(const BSTiterator &rhs) const{
			return (node != rhs.node);	
		}
		BSTiterator	operator-(std::size_t i) const{
			BSTiterator<T, Compare>	ret(*this);
			
			for (size_t j = 0; j < i; j++)
				ret--;
			return (ret);
		}
	};

	// BSTconstIterator
	template<typename T, class Compare>
	class BSTconstIterator
	{
	public:
		typedef typename T::value_type  			value_type;
		typedef typename value_type::first_type		key;
		typedef typename value_type::second_type	mapped_type;
		typedef std::ptrdiff_t						difference_type;
		typedef	const value_type*					pointer;
		typedef const value_type&					reference;
		typedef BSTconstIterator					iterator_category;

		const T		*node;
		const T		*TNULL;
		const T			*max;
		Compare	comp;

		BSTconstIterator(const Compare &comp = Compare())
			: node(NULL),
			TNULL(NULL),
			max(NULL),
			comp(comp){}
		BSTconstIterator(const T *node, const T *TNULL, const T *max, const Compare &comp = Compare())
			: node(node),
			TNULL(TNULL),
			max(max),
			comp(comp){}
		BSTconstIterator(const BSTconstIterator<T, Compare> &src)
			: node(src.node),
			TNULL(src.TNULL),
			comp(src.comp){}
		BSTconstIterator(const BSTiterator<T, Compare> &src)
			: node(src.node),
			TNULL(src.TNULL),
			max(src.max),
			comp(src.comp){}
		~BSTconstIterator(){}
		
		BSTconstIterator	&operator=(const BSTconstIterator &rhs){
			if (this == &rhs)
				return (*this);
			node = rhs.node;
			TNULL = rhs.TNULL;
			max = rhs.max;
			comp = rhs.comp;
			return (*this);
		}
		BSTconstIterator	&operator++(){
			if (!node)
				return (*this);
			const BstNode<const key, mapped_type> *current = node;
			if (node->right != TNULL && comp(node->data.first, node->right->data.first)){
				current = node->right;
				while (current->left != TNULL && comp(node->data.first, current->left->data.first))
					current = current->left;
			}
			else{
				while (current->parent){
					current = current->parent;
					if (comp(node->data.first, current->data.first))
						break ;
				}
			}
			if (comp(node->data.first, current->data.first))
				node = current;
			else
				node = current->parent;
			return (*this);
		}
		BSTconstIterator	operator++(int){
			BSTconstIterator it = *this;
			++(*this);
			return (it);
		}
		BSTconstIterator	&operator--(){
			const BstNode<const key, mapped_type>	*current = node;
			if (!node){
				node = max;
				return (*this);
			}
			if (node->left != TNULL && comp(node->left->data.first, node->data.first)){
				current = node->left;
				while (current->right != TNULL && comp(current->right->data.first, node->data.first))
					current = current->right;
				node = current;
				return (*this);
			}
			else{
				while(current->parent){
					current = current->parent;
					if (comp(current->data.first, node->data.first)){
						node = current;
						return (*this);
					}
				}
			}
			// at this point current is root ==> get bottom left node = min
			while (current->left && current->left != TNULL)
				current = current->left;
			node = current;
			return (*this);
		}
		BSTconstIterator	operator--(int){
			BSTconstIterator it = *this;
			--(*this);
			return (it);
		}
		value_type const	&operator*() const{
			return (node->data);
		}
		value_type const	*operator->() const{
			return (&node->data);
		}
		bool		operator==(const BSTconstIterator &rhs) const{
			return (node == rhs.node);
		}
		bool		operator!=(const BSTconstIterator &rhs) const{
			return (node != rhs.node);	
		}
		BSTconstIterator	operator-(std::size_t i) const{
			BSTconstIterator<T, Compare>	ret(*this);
			
			for (size_t j = 0; j < i; j++)
				ret--;
			return (ret);
		}
	};
	
}

#endif 