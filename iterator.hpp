/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:29:41 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/26 19:37:31 by asaboure         ###   ########.fr       */
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
		typedef	Iter::difference_type	difference_type;
		typedef	Iter::value_type		value_type;
		typedef Iter::pointer			pointer;
		typedef	Iter::reference			reference;
		typedef	Iter::iterator_category	iterator_category;

	private:
		
	public:
		iterator_traits();
		~iterator_traits();
	};
}

#endif