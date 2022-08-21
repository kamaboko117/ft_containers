/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTiterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:36:48 by asaboure          #+#    #+#             */
/*   Updated: 2022/08/21 15:21:59 by asaboure         ###   ########.fr       */
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
		Compare		comp;

		BSTiterator(const Compare &comp = Compare())
			: node(NULL),
			TNULL(NULL),
			comp(comp){}
		BSTiterator(BstNode<const key, mapped_type> *node, BstNode<const key, mapped_type> *TNULL, const Compare &comp = Compare())
			: node(node),
			TNULL(TNULL),
			comp(comp){}
		template<typename U, class Comp>
		BSTiterator(const BSTiterator<U, Comp> &src)
			: node(src.node),
			TNULL(src.TNULL),
			comp(src.comp){}
		~BSTiterator(){}
		
		BSTiterator	&operator=(const BSTiterator &rhs){
			if (this == &rhs)
				return (*this);
			node = rhs.node;
			TNULL = rhs.TNULL;
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
		Compare	comp;

		BSTconstIterator(const Compare &comp = Compare())
			: node(NULL),
			TNULL(NULL),
			comp(comp){}
		BSTconstIterator(const T *node, const T *TNULL, const Compare &comp = Compare())
			: node(node),
			TNULL(TNULL),
			comp(comp){}
		BSTconstIterator(const BSTconstIterator<T, Compare> &src)
			: node(src.node),
			TNULL(src.TNULL),
			comp(src.comp){}
		BSTconstIterator(const BSTiterator<T, Compare> &src)
			: node(src.node),
			TNULL(src.TNULL),
			comp(src.comp){}
		~BSTconstIterator(){}
		
		BSTconstIterator	&operator=(const BSTconstIterator &rhs){
			if (this == &rhs)
				return (*this);
			node = rhs.node;
			TNULL = rhs.TNULL;
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
			BstNode<const key, mapped_type>	*current = node;
			if (node->red == 2){
				node = node->parent;
				return (*this);
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