/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTiterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:36:48 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/30 18:26:34 by asaboure         ###   ########.fr       */
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
		typedef typename T::value_type 	value_type;
		typedef std::ptrdiff_t			difference_type;
		typedef value_type*				pointer;
		typedef value_type&				reference;
		typedef BSTiterator				iterator_category;

		T			*node;
		Compare		comp;

		BSTiterator(const Compare &comp = Compare())
			: node(NULL),
			comp(comp){}
		BSTiterator(BstNode<value_type> *node, const Compare &comp = Compare())
			: node(node),
			comp(comp){}
		template<typename U, class Comp>
		BSTiterator(const BSTiterator<U, Comp> &src)
			: node(src.node),
			comp(src.comp){}
		~BSTiterator(){}
		
		BSTiterator	&operator=(const BSTiterator &rhs){
			if (this == &rhs)
				return (*this);
			node = rhs.node;
			comp = rhs.comp;
			return (*this);
		}
		BSTiterator	&operator++(){
			if (!node)
				return (*this);
			BstNode<value_type> *current = node;
			if (node->right && comp(node->data.first, node->right->data.first)){
				current = node->right;
				while (current->left && comp(node->data.first, current->left->data.first))
					current = current->left;
			}
			else{
				if (!(node->parent)){
					node = node->right;
					return (*this);
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
			return (*this);
		}
		BSTiterator	operator++(int){
			BSTiterator it = *this;
			++(*this);
			return (it);
		}
		BSTiterator	&operator--(){
			BstNode<value_type>	*current = node;
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
		BSTiterator	operator--(int){
			BSTiterator it = *this;
			--(*this);
			return (it);
		}
		value_type	&operator*() const{
			return (node->data);
		}
		// T			&operator[](difference_type i){
		// 	return (node[i]);
		// }
		value_type	*operator->() const{
			return (&node->data);
		}
		bool		operator==(const BSTiterator &rhs) const{
			return (node == rhs.node);
		}
		bool		operator!=(const BSTiterator &rhs) const{
			return (node != rhs.node);	
		}
		// BSTiterator	operator+(std::size_t i) const{
		// 	return (BSTiterator(node + i));
		// }
		BSTiterator	operator-(std::size_t i) const{
			BSTiterator<T, Compare>	ret(*this);
			
			for (size_t j = 0; j < i; j++)
				ret--;
			return (ret);
		}
		// BSTiterator	&operator+=(difference_type n){
		// 	node += n;
		// 	return (*this);
		// }
		// BSTiterator	&operator-=(difference_type n){
		// 	node -= n;
		// 	return (*this);
		// }
		// T	*base() const{
		// 	return (node);
		// }
	};

// // iteraror non member operators
// 	template<typename T>
// 	bool	operator==(const BSTiterator<T> lhs, const BSTiterator<T> rhs){
//         return (lhs.base() == rhs.base());
//     }
// 	template<typename T_L, typename T_R>
//     bool	operator==(const BSTiterator<T_L> lhs, const BSTiterator<T_R> rhs)
//     {
//         return (lhs.base() == rhs.base());
//     }
// 	template<typename T>
// 	bool	operator!=(const BSTiterator<T> lhs, const BSTiterator<T> rhs)
//     {
//         return (lhs.base() != rhs.base());
//     }
// 	template<typename T_L, typename T_R>
//     bool	operator!=(const BSTiterator<T_L> lhs, const BSTiterator<T_R> rhs)
//     {
//         return (lhs.base() != rhs.base());
//     }
//     template<typename T>
//     bool	operator<(const BSTiterator<T> lhs, const BSTiterator<T> rhs)
//     {
//         return (lhs.base() < rhs.base());
//     }
// 	template<typename T_L, typename T_R>
//     bool	operator<(const BSTiterator<T_L> lhs, const BSTiterator<T_R> rhs)
//     {
//         return (lhs.base() < rhs.base());
//     }
// 	template<typename T>
//     bool	operator>(const BSTiterator<T> lhs, const BSTiterator<T> rhs)
//     {
//         return (lhs.base() > rhs.base());
//     }
//     template<typename T_L, typename T_R>
//     bool	operator>(const BSTiterator<T_L> lhs, const BSTiterator<T_R> rhs)
//     {
//         return (lhs.base() > rhs.base());
//     }
// 	template<typename T>
//     bool	operator<=(const BSTiterator<T> lhs, const BSTiterator<T> rhs)
//     {
//         return (lhs.base() <= rhs.base());
//     }
// 	template<typename T_L, typename T_R>
//     bool	operator<=(const BSTiterator<T_L> lhs, const BSTiterator<T_R> rhs)
//     {
//         return (lhs.base() <= rhs.base());
//     }
// 	template<typename T>
//     bool	operator>=(const BSTiterator<T> lhs, const BSTiterator<T> rhs)
//     {
//         return (lhs.base() >= rhs.base());
//     }
//     template<typename T_L, typename T_R>
//     bool	operator>=(const BSTiterator<T_L> lhs, const BSTiterator<T_R> rhs)
//     {
//         return (lhs.base() >= rhs.base());
//     }

// 	// template<typename T>	
// 	// typename BSTiterator<T>::difference_type	operator+(const BSTiterator<T> lhs, const BSTiterator<T> rhs){
//     //     return (lhs.base() + rhs.base());
//     // }
// 	// template<typename T_L, typename T_R>
//     // typename BSTiterator<T_L>::difference_type	operator+(const BSTiterator<T_L> lhs, const BSTiterator<T_R> rhs){
//     //     return (lhs.base() + rhs.base());
//     // }
// 	template<typename T>
//     ft::BSTiterator<T>	operator+(typename ft::BSTiterator<T>::difference_type n, typename ft::BSTiterator<T>& rai)
//     {
// 		return (&(*rai) + n);
// 	}
// 	template<typename T>
//     typename BSTiterator<T>::difference_type	operator-(const BSTiterator<T> lhs, const BSTiterator<T> rhs){
//         return (lhs.base() - rhs.base());
//     }
// 	template<typename T_L, typename T_R>
//     typename BSTiterator<T_L>::difference_type	operator-(const BSTiterator<T_L> lhs, const BSTiterator<T_R> rhs){
//         return (lhs.base() - rhs.base());
//     }

	// BSTconstIterator
	template<typename T, class Compare>
	class BSTconstIterator
	{
	public:
		typedef typename T::value_type  		value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef	const value_type*						pointer;
		typedef const value_type&						reference;
		typedef BSTconstIterator				iterator_category;

		T		*node;
		Compare	comp;

		BSTconstIterator(const Compare &comp = Compare())
			: node(NULL),
			comp(comp){}
		BSTconstIterator(T *node, const Compare &comp = Compare())
			: node(node),
			comp(comp){}
		BSTconstIterator(const BSTconstIterator<T, Compare> &src)
			: node(src.node),
			comp(src.comp){}
		BSTconstIterator(const BSTiterator<T, Compare> &src)
			: node(src.node),
			comp(src.comp){}
		~BSTconstIterator(){}
		
		BSTconstIterator	&operator=(const BSTconstIterator &rhs){
			if (this == &rhs)
				return (*this);
			node = rhs.node;
			comp = rhs.comp;
			return (*this);
		}
		// BSTconstIterator	&operator=(const BSTiterator<T, Compare> &rhs){
		// 	if (this == &rhs)
		// 		return (*this);
		// 	node = rhs.node;
		// 	comp = rhs.comp;
		// 	return (*this);
		// }
		BSTconstIterator	&operator++(){
			if (!node)
				return (*this);
			BstNode<value_type> *current = node;
			if (node->right && comp(node->data.first, node->right->data.first)){
				current = node->right;
				while (current->left && comp(node->data.first, current->left->data.first))
					current = current->left;
			}
			else{
				if (!(node->parent)){
					node = node->right;
					return (*this);
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
			return (*this);
		}
		BSTconstIterator	operator++(int){
			BSTconstIterator it = *this;
			++(*this);
			return (it);
		}
		BSTconstIterator	&operator--(){
			BstNode<value_type>	*current = node;
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
		// T			&operator[](difference_type i){
		// 	return (node[i]);
		// }
		value_type const	*operator->() const{
			return (&node->data);
		}
		bool		operator==(const BSTconstIterator &rhs) const{
			return (node == rhs.node);
		}
		bool		operator!=(const BSTconstIterator &rhs) const{
			return (node != rhs.node);	
		}
		// BSTconstIterator	operator+(std::size_t i) const{
		// 	return (BSTconstIterator(node + i));
		// }
		BSTconstIterator	operator-(std::size_t i) const{
			BSTconstIterator<T, Compare>	ret(*this);
			
			for (size_t j = 0; j < i; j++)
				ret--;
			return (ret);
		}
		// BSTconstIterator	&operator+=(difference_type n){
		// 	node += n;
		// 	return (*this);
		// }
		// BSTconstIterator	&operator-=(difference_type n){
		// 	node -= n;
		// 	return (*this);
		// }
		// T	*base() const{
		// 	return (node);
		// }
	};
	
}

#endif 