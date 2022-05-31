/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:29:41 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/31 14:57:31 by asaboure         ###   ########.fr       */
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

		reverse_iterator();
		explicit reverse_iterator(iterator_type it);
		reverse_iterator(const reverse_iterator<Iter> &src);

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
	bool	operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter>
	bool	operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter>
	bool	operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter>
	bool	operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter>
	bool	operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter>
	bool	operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);
	template<class Iter>
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &rev_it);
	template<class Iter>
	typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs);

}	

#endif