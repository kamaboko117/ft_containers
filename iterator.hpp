/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:29:41 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/01 20:30:19 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template<class Iter>
	class iterator_traits
	{
	public:
		typedef	typename Iter::difference_type		difference_type;
		typedef	typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef	typename Iter::reference			reference;
		typedef	typename Iter::iterator_category	iterator_category;

	private:
		
	public:
		iterator_traits();
		~iterator_traits();
	};

	template<class Iter>
	class reverse_iterator
	{
	public:
		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;

	private:
		iterator_type	_elem;
	public:
		reverse_iterator();
		explicit reverse_iterator(iterator_type it);
		template<class Iter2>
		reverse_iterator(const reverse_iterator<Iter2> &src);

		reference			operator*() const;
		reverse_iterator	operator+(difference_type rhs) const;
		reverse_iterator	&operator+();
		reverse_iterator	operator++(int);
		reverse_iterator	&operator+=(difference_type rhs);
		reverse_iterator	operator-(difference_type rhs) const;
		reverse_iterator	&operator--();
		reverse_iterator	operator--(int);
		reverse_iterator	&operator-=(difference_type rhs);
		pointer				operator->() const;	
		reference			operator[](difference_type idx) const;
		
		iterator_type	base() const;
	};

	template<class Iter>
	reverse_iterator<Iter>::reverse_iterator()
		: _elem(){}

	template<class Iter>
	reverse_iterator<Iter>::reverse_iterator(iterator_type it)
		: _elem(it){}
	
	template<class Iter>
	template<class Iter2>
	reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<Iter2> &src)
		: _elem(src.base()){}

	template<class Iter>
	typename reverse_iterator<Iter>::iterator_type	reverse_iterator<Iter>::base() const{
		return (_elem);
	}
	
//NON MEMBER OPERATORS
	template<class Iter>
	bool	operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter_L, class Iter_R>
	bool	operator==(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs);
	template<class Iter>
	bool	operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter_L, class Iter_R>
	bool	operator!=(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs);
	template<class Iter>
	bool	operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter_L, class Iter_R>
	bool	operator<(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs);
	template<class Iter>
	bool	operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter_L, class Iter_R>
	bool	operator<=(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs);
	template<class Iter>
	bool	operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter_L, class Iter_R>
	bool	operator>(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs);
	template<class Iter>
	bool	operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter_L, class Iter_R>
	bool	operator>=(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs);
	template<class Iter>
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &rev_it);
	template<class Iter>
	typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter_L, class Iter_R>
	bool	operator-(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs);
}	

#endif