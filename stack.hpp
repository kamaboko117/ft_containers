/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:30:16 by asaboure          #+#    #+#             */
/*   Updated: 2022/06/29 20:25:23 by asaboure         ###   ########.fr       */
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

		bool				empty() const;
		size_type			size() const;
		value_type			&top();
		const value_type	&top() const;
		void				push(const value_type &val);
		void				pop();

		friend	bool	operator==(const stack &lhs, const stack &rhs){
			return (lhs._ctnr == rhs._ctnr);
		};
		friend bool 	operator!=(const stack &lhs, const stack& rhs){
			return lhs._ctnr != rhs._ctnr;
		}
        friend bool 	operator<(const stack &lhs, const stack& rhs){
			return lhs._ctnr < rhs._ctnr;
		}
        friend bool 	operator<=(const stack &lhs, const stack& rhs){
			return lhs._ctnr <= rhs._ctnr;
		}
        friend bool 	operator>(const stack &lhs, const stack& rhs){
			return lhs._ctnr > rhs._ctnr;
		}
        friend bool 	operator>=(const stack &lhs, const stack& rhs){
			return lhs._ctnr >= rhs._ctnr;
		}
	};

	template<class T, class Container>
	stack<T, Container>
	::stack(const container_type &ctnr)
		: _ctnr(ctnr){}

	template<class T, class Container>
	stack<T, Container>
	::~stack(){}

	template<class T, class Container>
	typename stack<T, Container>::size_type	stack<T, Container>
	::size() const{
		return (_ctnr.size());
	}	

	template<class T, class Container>
	bool	stack<T, Container>
	::empty() const{
		return (_ctnr.empty());
	}

	template<class T, class Container>
	void	stack<T, Container>
	::push(const value_type &val){
		_ctnr.push_back(val);
	}

	template<class T, class Container>
	typename stack<T, Container>::value_type	&stack<T, Container>
	::top(){
		return (_ctnr.back());
	}

	template<class T, class Container>
	typename stack<T, Container>::value_type const	&stack<T, Container>
	::top() const{
		return (_ctnr.back());
	}

	template<class T, class Container>
	void	stack<T, Container>
	::pop(){
		_ctnr.pop_back();
	}
}
