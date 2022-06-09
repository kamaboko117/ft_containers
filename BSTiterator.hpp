/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTiterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:36:48 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/09 18:35:38 by asaboure         ###   ########.fr       */
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
		typedef T 				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef	value_type*		pointer;
		typedef value_type&		reference;
		typedef BSTiterator		BSTiterator_category;
	private:
		BstNode<T>		*node;
		Compare			comp;
	public:
		BSTiterator(const Compare &comp = Compare())
			: node(),
			comp(comp){}
		BSTiterator(T *node, const Compare &comp = Compare())
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
			T *current = node;
			
			if (comp(node->data.first, node->right.data.first))
				current = node->right;
			else{
				while(current->parent && comp(node->parent.data.first, current->data.first))
					current = current->parent;
			}
			node = current;
			return (*this);
		}
		BSTiterator	operator++(int){
			BSTiterator it = *this;
			++(*this);
			return (it);
		}
		BSTiterator	&operator--(){
			T	*current;
			
			if (comp(node->left.data.first, node->data.first))
				current = node->left;
			else{
				while(current->parent && comp(node->data.first, current->parent.data.first))
					current = current->parent;
			}
			node = current;
			return (*this);
		}
		BSTiterator	operator--(int){
			BSTiterator it = *this;
			--(*this);
			return (it);
		}
		T			&operator*() const{
			return (*node);
		}
		// T			&operator[](difference_type i){
		// 	return (node[i]);
		// }
		T			*operator->(){
			return (node);
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
		// BSTiterator	operator-(std::size_t i) const{
		// 	return (BSTiterator(node - i));
		// }
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
	
	
}

#endif 