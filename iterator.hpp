/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:29:41 by asaboure          #+#    #+#             */
/*   Updated: 2022/05/27 13:56:03 by asaboure         ###   ########.fr       */
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
}

#endif