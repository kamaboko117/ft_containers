/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:11:12 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/02 19:52:25 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <functional>
# include "iterator.hpp"

namespace ft
{
	
	template<class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef pair<const key_type, mapped_type>	value_type;
		typedef Compare								key_compare;
		//value_compare?
		typedef	Alloc								allocator_type;
		typedef allocator_type::reference			reference;
		typedef allocator_type::const_reference		const_reference;
		typedef allocator_type::pointer				pointer;
		typedef allocator_type::const_pointer		const_pointer;
		//iterator
		//const_iterator
		//reverse_iterator
		//const_reverse_iterator
		//difference_type
		typedef std::size_t							size_type;
	private:
		
	public:
		map();
		~map();
	};
	
}

#endif