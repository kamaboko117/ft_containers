/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:29:41 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/02 17:45:20 by asaboure         ###   ########.fr       */
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
		reverse_iterator	&operator++();
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

//CONSTRUCT
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

//OPERATORS
	template<class Iter>
	typename reverse_iterator<Iter>::reference	reverse_iterator<Iter>::operator*() const{
		return (*(_elem - 1));
	}

	template<class Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator+(typename reverse_iterator<Iter>::difference_type rhs) const{
		return(reverse_iterator(_elem - rhs));
	}

	template<class Iter>
	reverse_iterator<Iter>	&reverse_iterator<Iter>::operator++(){
		--_elem;
		return (*this);
	}

	template<class Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator++(int){
		reverse_iterator	tmp = *this;
		++(*this);
		return (tmp);
	}
	
	template<class Iter>
	reverse_iterator<Iter>	&reverse_iterator<Iter>::operator+=(typename reverse_iterator<Iter>::difference_type n){
		_elem -= n;
		return (*this);
	}

	template<class Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator-(typename reverse_iterator<Iter>::difference_type rhs) const{
		return(reverse_iterator(_elem + rhs));
	}
	
	template<class Iter>
	reverse_iterator<Iter>	&reverse_iterator<Iter>::operator--(){
		++_elem;
		return (*this);
	}

	template<class Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator--(int){
		reverse_iterator	tmp = *this;
		--(*this);
		return (tmp);
	}
	
	template<class Iter>
	reverse_iterator<Iter>	&reverse_iterator<Iter>::operator-=(typename reverse_iterator<Iter>::difference_type n){
		_elem += n;
		return (*this);
	}

	template<class Iter>
	typename reverse_iterator<Iter>::pointer	reverse_iterator<Iter>::operator->() const{
		return (&(operator*()));
	}

	template<class Iter>
	typename reverse_iterator<Iter>::reference	reverse_iterator<Iter>::operator[](typename reverse_iterator<Iter>::difference_type idx) const{
		return (base()[-idx - 1]);	
	}
//ETC
	template<class Iter>
	typename reverse_iterator<Iter>::iterator_type	reverse_iterator<Iter>::base() const{
		return (_elem);
	}
	
//NON MEMBER OPERATORS
	template<class Iter>
	bool	operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs){
		return (lhs.base() == rhs.base());
	}
	
	template<class Iter_L, class Iter_R>
	bool	operator==(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs){
		return (lhs.base() == rhs.base());
	}
	
	template<class Iter>
	bool	operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs){
		return (lhs.base() != rhs.base());
	}
	
	template<class Iter_L, class Iter_R>
	bool	operator!=(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs){
		return (lhs.base() != rhs.base());
	}
	
	template<class Iter>
	bool	operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs){
		return (lhs.base() > rhs.base());
	}
	
	template<class Iter_L, class Iter_R>
	bool	operator<(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs){
		return (lhs.base() > rhs.base());
	}
	
	template<class Iter>
	bool	operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs){
		return (lhs.base() >= rhs.base());
	}
	
	template<class Iter_L, class Iter_R>
	bool	operator<=(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs){
		return (lhs.base() >= rhs.base());
	}
	
	template<class Iter>
	bool	operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs){
		return (lhs.base() < rhs.base());
	}
	
	template<class Iter_L, class Iter_R>
	bool	operator>(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs){
		return (lhs.base() < rhs.base());
	}
	
	template<class Iter>
	bool	operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs){
		return (lhs.base() <= rhs.base());
	}
	
	template<class Iter_L, class Iter_R>
	bool	operator>=(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs){
		return (lhs.base() <= rhs.base());
	}
	
	template<class Iter>
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &rev_it){
		return (rev_it + n);	
	}
	
	template<class Iter>
	typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs){
	return (lhs.base() - rhs.base());
	}
	
	template<class Iter_L, class Iter_R>
	bool	operator-(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs){
		return (lhs.base() - rhs.base());
	}
}	

#endif