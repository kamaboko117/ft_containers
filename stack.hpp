/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:30:16 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/29 16:02:36 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef	std::size_t	size_type;
	private:
		container_type	_ctnr;
	public:
		explicit stack(const container_type &ctnr = container_type());
		~stack();

		size_type	size() const;
	};

	template<class T, class Container>
	stack<T, Container>::stack(const container_type &ctnr)
		: _ctnr(ctnr){}

	template<class T, class Container>
	stack<T, Container>::~stack(){}

	template<class T, class Container>
	typename stack<T, Container>::size_type	stack<T, Container>::size() const{
		return (_ctnr.size());
	}	
}